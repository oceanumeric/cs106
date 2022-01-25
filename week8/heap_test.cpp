#include<iostream>
#include<vector>
#include "binary_heaps.h"


int main() {
    std::vector<int> v1 = {4, 5, 19, 21, 22, 27, 23, 35, 45};
    MaxHeap mh = MaxHeap();
    for (auto elem : v1) {
        mh.insert(elem);
    }
    std::cout << "The maxium value is " << mh.get_max() << "\n";
    mh.insert(42);
    std::cout << "The maxium value is " << mh.get_max() << "\n";
    mh.insert(99);
    mh.insert(0);
    mh.insert(39);
    mh.insert(35);  // you can insert the same value 
    std::cout << "The maxium value is " << mh.get_max() << "\n";
    int temp = mh.extract_max();
    std::cout << "The maxium value is " << temp << "\n";
    std::cout << "The maxium value is " << mh.extract_max() << "\n";
    mh.print();
    std::cout << "The maxium value is " << mh.extract_max()  << "\n";
    mh.print();
    std::cout << "The maxium value is " << mh.extract_max() << "\n";
    mh.print();
    std::cout << "The maxium value is " << mh.extract_max() << "\n";
    mh.print();

    return 0;
}