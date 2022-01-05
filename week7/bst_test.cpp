#include<iostream>
#include<vector>
#include "bst.h"


/*
Test BST: 
void add(int elem);
void remove(int elem);
void clear();
int size() const;
bool is_in(int elem) const;  
int find_min() const;
int find_max() const; 
*/


int main() {
    BST bt; 
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 8};
    std::cout << "Adding the following element to BST bt: ";
    for (int elem: v1) {
        std::cout << elem << " ";
        bt.add(elem);
    }
    std::cout << "\n";
    std::cout << "Print out the binary search tree in order: \n";
    bt.in_order_print();
    std::cout << "\n";
    bt.remove(2);
    int max = bt.find_max();
    std::cout << "The maximum is " << max << "\n";
    int min = bt.find_min();
    std::cout << "The minimum is " << min << "\n";
    std::cout << "Print out the binary search tree in order: \n";
    bt.in_order_print();
    std::cout << "\n";
    std::vector<int> v2 = {5, 10};
    for (int elem: v2) {
        if (bt.is_in(elem)){
            std::cout << elem << " is in the set\n";
        } else {
            std::cout << elem << " is NOT in the set\n";
        }
    }
    bt.clear();
    std::cout << bt.size() << "\n";

    return 0;
}