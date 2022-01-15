/*
Tree Traversal 
Reference: https://en.wikipedia.org/wiki/Tree_traversal
 */
#include <iostream>

// Step I: build up a binary tree mannually 

template <typename ValueT>
struct Node {
    ValueT data;  // node for storing the data
    Node* left;  // pointer to link the node 
    Node* right; 

    // constructor
    Node(ValueT elem) {
        data = elem;
        left = nullptr;
        right = nullptr; 
    }
};


template <typename ValueT>
void print_tree(Node<ValueT>* root){
    if (root != nullptr) {
        // pre-order
        // std::cout << root->data << " ";   
        print_tree(root->left);
        // in-order
        // std::cout << root->data << " ";  
        print_tree(root->right);
        // post-order
        std::cout << root->data << " ";
    }
}

template <typename ValueT>
bool contains(Node<ValueT>* root, ValueT value) {
    // base case
    if (root != nullptr) {
        if (root->data == value) {
        return true;
        }
        if (contains(root->left, value) || contains(root->right, value)) {
            return true;
        }
    }
    return false;
}

template <typename ValueT>
ValueT get_min(Node<ValueT>*root) {
    if (root->left == nullptr) {
        return root->data;
    }
    return get_min(root->left);
}

template <typename ValueT>
ValueT get_max(Node<ValueT>*root) {
    if (root->right == nullptr) {
        return root->data;
    }
    return get_max(root->right);
}


int main() {
    /*
                    F
                  /     \
                B         G
               /  \         \
              A    D          I
                  /  \      /
                 C   E     H
    */
    Node<char>* root = new Node<char>('F'); 
    root->left = new Node<char>('B');
    root->left->left = new Node<char>('A');
    root->left->right = new Node<char>('D');
    root->left->right->left = new Node<char>('C');
    root->left->right->right = new Node<char>('E');
    root->right = new Node<char>('G');
    root->right->right = new Node<char>('I');
    root->right->right->left = new Node<char>('H');
    print_tree(root);
    if (contains(root, 'A')) {
        std::cout << "A is in the tree\n";
    } else {
        std::cout << "A is not in the tree\n";
    }

    if (contains(root, 'P')) {
        std::cout << "P is in the tree\n";
    } else {
        std::cout << "P is not in the tree\n";
    }

    std::cout << "The MINIMUM value is " << get_min(root) << "\n";
    std::cout << "The MAXIMUM value is " << get_max(root) << "\n";

    /*
                    8
                  /     \
                5         11
               /  \         \
              2    7    10   19
               \               \
                4              25
    */
    
    Node<int>* root2 = new Node<int>(8);
    root2->left = new Node<int>(5);
    root2->left->left = new Node<int>(2);
    root2->left->right = new Node<int>(7);
    root2->left->left->right = new Node<int>(4);
    root2->right = new Node<int>(11);
    root2->right->left = new Node<int>(10);
    root2->right->right = new Node<int>(19);
    root2->right->right->right = new Node<int>(25); 
    print_tree(root2);

    std::cout << "The MINIMUM value is " << get_min(root2) << "\n";
    std::cout << "The MAXIMUM value is " << get_max(root2) << "\n";
    
    return 0; 
}

