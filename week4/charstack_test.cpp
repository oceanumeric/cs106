#include "charstack.h"
#include<iostream>


int main() {

    CharStack cs;  // initialize the char stack 
    cs.push('a');
    cs.push('b');
    std::cout << cs.peek() << "\n";
    cs.push('c');
    cs.push('d');
    std::cout << cs.pop() << "\n";
    std::cout << cs.peek() << "\n";
    std::cout << cs.size() << "\n";
    std::cout << cs.is_empty() << "\n";

    return 0;
}