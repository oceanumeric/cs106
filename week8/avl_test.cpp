#include<iostream>
#include<vector>
#include "avl.h"


int main() {
    AVL avlt; 
    std::vector<int> v1 {13, 15, 18, 25, 37, 40, 32, 1, 2, 3, 11, 8, 6, 10};
    // insert 0 or 5 or 16 or 43 would result in an unbalanced tree 
    for (auto elem : v1) {
        avlt.insert(elem);
        std::cout << "\n";
        std::cout << avlt.get_balance();
    }
    avlt.print();
    avlt.insert(43);
    std::cout << "\n";
    avlt.print();
    std::cout << avlt.get_balance() << " the size is " << avlt.size() << "\n";
    for (auto elem : v1) {
        avlt.remove(elem);
    }
    avlt.print();
    return 0;
}