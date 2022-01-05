#include<iostream>
#include<vector>
#include<queue>

struct TreeNode {
    int data;  // it could be string or int 
    std::vector<TreeNode*> children;  // a vector or a children 
};


TreeNode *new_node(int elem) {
    TreeNode *temp = new TreeNode;
    temp->data = elem;
    return temp;
}

void print_out_tree(TreeNode *root) {
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


int main() {
    TreeNode *root = new_node(2); 
    (root->children).push_back(new_node(10));
    (root->children).push_back(new_node(34));
    (root->children).push_back(new_node(56));
    (root->children).push_back(new_node(100));
    (root->children[0]->children).push_back(new_node(77));
    (root->children[0]->children).push_back(new_node(88));
    (root->children[2]->children).push_back(new_node(1));
    (root->children[3]->children).push_back(new_node(7));
    (root->children[3]->children).push_back(new_node(8));
    (root->children[3]->children).push_back(new_node(9));

    std::cout << "Level order traversal Before Mirroring\n";
    print_out_tree(root);
    return 0; 
}