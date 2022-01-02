/*Implementing maps (dictionary) with djb hash function

A good hash function must have the following two properties:
    1. the function must be inexpensive to compute
    2. the function should distribute keys as uniformly as possible acorss the
       integer range 
*/
#ifndef STRINGMAP_H
#define STRINGMAP_H
#include<string>


const int HASH_SEED = 5381;  // https://theartincode.stanis.me/008-djb2/
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;  // to maks the result 


int hash_code(const std::string & str) {
    unsigned hash = HASH_SEED;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        hash = HASH_MULTIPLIER * hash + str[i];
    }

    return int(hash & HASH_MASK);
}


class StringMap {
    public:
        // constructor and descructor 
        StringMap();
        ~StringMap();
        void put(const std::string & key, const std::string & value);
        std::string get(const std::string & key);
    private:
        struct  Node
        {
            std::string key;
            std::string value; 
            Node *link;
        };

        static const int INITIAL_BUCKET_COUNT  = 13;  // buckent range 

        // instance variables
        Node **buckets;  // a pointer to a pointer 
        int n_buckents;

        // private methods
        Node *find_node(int index, const std::string & key) const; 
        
};


StringMap::StringMap() {
    n_buckents = INITIAL_BUCKET_COUNT;
    buckets = new Node*[n_buckents];
    for (int i = 0; i < n_buckents; i++){
        buckets[i] = nullptr;
    }
}


StringMap::~StringMap() {
    for (int i = 0; i < n_buckents; i++){
        Node *temp = buckets[i];
        while (temp != nullptr) {
            Node *old_node = temp; 
            temp = temp->link;
            delete old_node;
        }
    }
}


void StringMap::put(const std::string & key, const std::string & value) {
    int index = hash_code(key) % n_buckents;
    Node *temp = find_node(index, key);
    if (temp == nullptr) {
        temp = new Node; 
        temp->key = key;
        temp->link = buckets[index];  // link the buckets 
        buckets[index] = temp; 
    }
    temp->value = value; 
}


std::string StringMap::get(const std::string & key) {
    int index = hash_code(key) % n_buckents;
    Node *result = find_node(index, key);
    return (result == nullptr) ? "" : result->value;
}


StringMap::Node *StringMap::find_node(int index, const std::string & key) const {
    Node *nd = buckets[index];
    while (nd != nullptr && key != nd->key) {
        nd = nd->link;
    }
    return nd; 
}


#endif