/*
Implement the set with the binary tree 
*/

// to implement the set you could use the following class
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


// to implement the map you could use the following class 
template <typename ValueT>
struct Node {
    ValueT key;  // node for storing the data
    ValueT value;
    Node* left;  // pointer to link the node 
    Node* right; 

    // constructor
    Node(ValueT elem, ValueT data) {
        key = elem;
        value = data;
        left = nullptr;
        right = nullptr; 
    }
};


// to build up a dictionary, you could use the following one 
struct TrieNode {
    bool is_world;
    TrieNode* children[26];
};

