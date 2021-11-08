#include <iostream>


int square (int n);


int main() {

    int n;

    std::cout << "This program calculates the square of an integer" << std::endl;
    std::cout << "Please enter an integer: ";
    std::cin >> n;
    std::cout << "The square of " << n << " is " << square(n) << std::endl;

    return 0;
}


int square (int n) {
    return n*n;
}