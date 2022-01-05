/*
Implement a genera tree 
*/
#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<vector>
#include<queue>

/* binary tree node example
template <typename T>
struct TreeNode
{
    T data;  // it could be string or int 
    TreeNode *left;
    TreeNode *right;
};
 */
// a general tree 
// there is no in-place order but only hirerachy 
// utility function to construct a new node 
template <typename T>
struct TreeNode {
    T data;  // it could be string or int 
    std::vector<TreeNode*> children;  // a vector or a children 
};

template <typename T>
TreeNode<T> *new_node(T elem) {
    TreeNode *temp = new TreeNode;
    temp->data = elem;
    return temp;
}


template <typename T>
class Tree {
    public:
        // constructor and descructor
        Tree();
        ~Tree();
        void clear(); 
        void print_out_tree();
        
};




template <typename T>
Tree<T>::Tree() {
    TreeNode *root = new TreeNode;
    root = nullptr;
}

template <typename T>
Tree<T>::~Tree() {
    clear();
}

template <typename T>
void Tree<T>::print_out_tree() {
    if (root == nullptr) return; 

    // use queue to track the tree
    std::queue<TreeNode *> qtree; 
    qtree.push(root);
    while (!qtree.empty()) {
        int n = qtree.size();
        while (n > 0) {
            // Dequeue an item from queue and print it
            TreeNode *temp = qtree.front();
            qtree.pop();
            std::cout << temp->data << " ";
            // Enqueue all children of the dequeued item
            for (int i = 0; i < temp->children.size(); i++) {
                qtree.push(temp->children[i]);
            }
            n --; 
        }
        std::cout << "\n";  // // Print new line between two levels
    }
}








#endif