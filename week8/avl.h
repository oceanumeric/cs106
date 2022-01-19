/*
AVL: self-balancing binary tree 
Reference: mit-6.006 (2020) Lecture 20
an in-order search tree before a rotation stays an in-order search tree !! 
or you can use the binary search tree property (ranking the node)
http://courses.washington.edu/css343/zander/NotesProbs/AVLtree.pdf
http://www.mathcs.emory.edu/~cheung/Courses/253/Syllabus/Trees/AVL-delete.html
*/
#ifndef AVL_H
#define AVL_H
#include<iostream>
#include<algorithm>


class AVL {
    public:
        // constructor 
        AVL();
        ~AVL();
        void insert(int x);
        void remove(int x);
        void clear();
        void print() const;
        int size() const; 
        int get_balance();
    private: 
        // node
        struct node {
            int data;
            node* left; 
            node* right; 
            int height; 
        };
        // root
        node* root;
        int count;

        void _make_empty(node* r) {
            if (r == nullptr) return;
            _make_empty(r->left);
            _make_empty(r->right);
            delete r; 
        }

        int _get_height(node* n) {
            return (n == nullptr ? -1 : n->height);  // height(one_node) = 0 
        }

        node* _right_rotate(node* &y) {
            // left-left case, passing by reference 
            node* new_head  = y->left;
            y->left = new_head->right;
            new_head->right = y;
            y->height = 1 + std::max(_get_height(y->left), _get_height(y->right));
            new_head->height = 1 + std::max(_get_height(new_head->left),
                                                _get_height(new_head->right));
            
            return new_head;
        }

        node* _left_rotate(node* &x) {
            // right-right case, passing by reference 
            node* new_head = x->right;
            x->right = new_head->left; 
            new_head->left = x; 
            x->height = 1 + std::max(_get_height(x->left), _get_height(x->right));
            new_head->height = 1 + std::max(_get_height(new_head->left), 
                                                _get_height(new_head->right));
            
            return new_head;
        }

        node* _double_left_rotate(node* &z) {
            // right-left case 
            z->right = _right_rotate(z->right);
            return _left_rotate(z);
        }

        node* _double_right_rotate(node* &z) {
            // left-right case 
            z->left = _left_rotate(z->left);
            return _right_rotate(z);
        }

        node* _insert(node* r, int elem) {

            if (r == nullptr) {
                r = new node; 
                r->data = elem;
                r->height = 0; 
                r->left = r->right = nullptr;
                return r; 
            } 

            if (elem < r->data) {
                r->left = _insert(r->left, elem);  // insert recursively 
                // check the balance 
                int bal = _get_height(r->left) - _get_height(r->right);
                if (bal > 1) {
                    if (elem < r->left->data) {
                        // left-left case
                        r = _right_rotate(r);
                    } else {
                        // left-right, do double right rotation
                        r = _double_right_rotate(r);
                    }
                }
            } else if (elem > r->data) {
                // insert recursively 
                r->right = _insert(r->right, elem);
                // check the balance 
                int bal = _get_height(r->right) - _get_height(r->left); 
                if (bal > 1) {
                    if (elem > r->right->data) {
                        // right-right case 
                        r = _left_rotate(r);
                    } else {
                        // right-left case, double rotation
                        r = _double_left_rotate(r);
                    }
                }
            }

            // update the height 
            r->height = std::max(_get_height(r->left), _get_height(r->right)) + 1;
            return r; 
        }

        node* _find_min(node* n) const {
            if (n == nullptr) {
                return NULL; 
            }
            if (n->left == nullptr) {
                return n;
            }

            return _find_min(n->left);
        }

        node* _find_max(node* n) const {
            if (n == nullptr) {
                return NULL;
            }
            if (n->right == nullptr) {
                return n;
            }

            return _find_max(n->right);
        }

        node* _remove(node*r, int elem) {
            node* temp;

            // empty-tree case 
            if (r == nullptr) return nullptr;

            // seach for elem recursively 
            if (elem < r->data) {
                r->left = _remove(r->left, elem);
            } else if (elem > r->data) {
                r->right = _remove(r->right, elem);
            } else if (r->left && r->right) {
                // elem found 
                // base case: with two childeren 
                // use the samlest node in the right-most tree to replace 
                temp = _find_min(r->right);
                r->data = temp->data; 
                r->right = _remove(r->right, r->data); // until it reached nullptr
            } else {
                // with one or zero child 
                temp = r;
                if (r->left == nullptr) {
                    r = r->right; 
                } else if (r->right == nullptr) {
                    r = r->left;
                } else {
                    delete temp;
                }
            }

            // the leaf of the tree after searching 
            if (r == nullptr) return r; 

            // update the balance
            r->height = std::max(_get_height(r->left), _get_height(r->right)) + 1;
            int bal = _get_height(r->left) - _get_height(r->right);
            // if bal is at least 2 
            if (bal > 1) {
                // node delted from the right causes unbalance
                // which means we have left-heavy subtree 
                // we need to operate rotate right or double rotate right
                if (_get_height(r->left->left) - _get_height(r->left->right) == 1) {
                    // left-left case 
                    return _right_rotate(r);
                } else {
                    // left-right case 
                    return _double_right_rotate(r);
                }
            } else if (bal < -1) {
                // right-heavy subtree 
                // we need to operate rotate left 
                if (_get_height(r->right->right) - _get_height(r->right->left) == 1){
                    // right-right case 
                    return _left_rotate(r);
                } else {
                    // right-left case
                    return _double_left_rotate(r);
                }
            }

            return r; 
        }

        int _get_balance(node* r) {
            if (r == nullptr) {
                return 0;
            } else {
                return _get_height(r->left) - _get_height(r->right);
            }

        }
        
        void _in_order_print(node* r) const {
            if (r == nullptr) return;
            _in_order_print(r->left);
            std::cout << r->data << " "; 
            _in_order_print(r->right);
        }

        node* _clear(node* r) {
            if (r == nullptr) return nullptr;
            _clear(r->left);
            _clear(r->right);
            delete r;
            return nullptr;
        }

};

AVL::AVL() {
    // constructor 
    root = nullptr;
    count = 0;
}

AVL::~AVL() {
    clear();
}

void AVL::clear() {
    // if you do:
    // _clear(root)
    // delete root
    // it will give tou double free error 
    root = _clear(root);
    delete root;
    count = 0 ;
}

void AVL::insert(int x) {
    root = _insert(root, x);
    count++;
}

void AVL::remove(int x) {
    root = _remove(root, x);
    if (root == nullptr) {
        throw std::runtime_error("There is no such element");
    } else {
        count--; 
        std::cout << x << " has been removed\n";
        std::cout << "Now the size of set is " << count << "\n";
    }
}

void AVL::print() const {
    _in_order_print(root);
}

int AVL::size() const {
    return count;
}

int AVL::get_balance() {
    return _get_balance(root);
}


#endif
