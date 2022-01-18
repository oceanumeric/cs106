/*
Implement Binary Tree 
Reference: https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-spring-2020/
*/
#ifndef BST_H
#define BST_H
#include<iostream>


// binary search tree with integer 
class BST {
    public:
        // constructor and destructor  
        BST();
        ~BST();
        // class methods 
        void add(int elem);
        void remove(int elem);
        void in_order_print() const;
        void clear();
        int size() const;
        bool is_in(int elem) const;  
        int find_min() const;
        int find_max() const; 
    private:
        // nested class Node 
        struct Node
        {
            int data;
            Node* left;
            Node* right;
            
        };
        // instance 
        Node *root;
        int count;
        // utility helper function
        Node* _insert(int x, Node* n) {
            if (n == nullptr) {
                n = new Node;
                n->data = x;
                n->left = n->right = nullptr;
            }
            else if (x < n->data) {
                n->left = _insert(x, n->left);  // call 
            } else {
                n->right = _insert(x, n->right);
            }

            return n; 
        }

        void _in_order(Node* n) const {
            // left - node - right
            if (n == nullptr) return;
            _in_order(n->left);
            std::cout << n->data << " ";
            _in_order(n->right);

        }

        Node* _search(int x, Node* n) const {
            // base case
            if (n == nullptr) {
                return nullptr;
            } 
            if (x == n->data) {
                return n;
            }
            if (x < n->data) {
                return _search(x, n->left);
            } else {
               return _search(x, n->right);
            }
        }

        Node* _find_min(Node* n) const {
            if (n == nullptr) {
                return NULL; 
            }
            if (n->left == nullptr) {
                return n;
            }

            return _find_min(n->left);
        }

        Node* _find_max(Node *n) const {
            if (n == nullptr) {
                return NULL;
            }
            if (n->right == nullptr) {
                return n;
            }

            return _find_max(n->right);
        }

        Node* _remove(int elem, Node* n) {
            Node* temp;
            if (n == nullptr) {
                return nullptr;
            } else if (elem < n->data) {
                n->left = _remove(elem, n->left);
            } else if (elem > n->data) {
                n->right = _remove(elem, n->right);
            } else if (n->left && n->right) {
                // base case elem = n->dat with two children 
                // two children 
                // use the samlest node in the right-most tree 
                temp = _find_min(n->right);
                n->data = temp->data;  // replace 
                n->right = _remove(n->data, n->right);  // now remove recursively

            } else {
                // base case elem = n->dat with only one child 
                temp = n; 
                if (n->left == nullptr) {
                    n = n->right; // bypass, use the right side to replace the node
                } else if (n->right == nullptr) {
                    n = n->left;
                }
                // base case elem = n->data with no child (a leaf);
                delete temp;  // just delete it (release)

            }

            return n; 

        }

        Node* _clear(Node* n) {
            // base case 
            if (n == nullptr) {
                return nullptr;
            }
            _clear(n->left);
            _clear(n->right);
            delete n;
            return nullptr;
        }


};

BST::BST() {
    root = nullptr;
    count = 0;
}

BST::~BST() {
    clear();
}

void BST::add(int elem) {
    root = _insert(elem, root);
    count++;
}

void BST::in_order_print() const {
    _in_order(root);
}

int BST::size() const {
    return count;
}

bool BST::is_in(int elem) const {
    if (root == nullptr) {
        return false;
    } else {
        Node* temp = _search(elem, root);
        if (temp == nullptr) {
            return false;
        } else {
            return true; 
        }
    }
}

int BST::find_min() const {
    Node* temp = _find_min(root);
    return temp->data;
}

int BST::find_max() const {
    Node* temp = _find_max(root);
    return temp->data; 
}

void BST::remove(int elem) {
    root = _remove(elem, root);
    if (root == nullptr) {
        throw std::runtime_error("There is no such element");
    } else {
        count--; 
        std::cout << elem << " has been removed\n";
        std::cout << "Now the size of set is " << count << "\n";
    }
}

void BST::clear() {
    root = _clear(root);
    delete root;
    count = 0;
}





#endif