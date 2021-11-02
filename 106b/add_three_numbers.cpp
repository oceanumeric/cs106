#include <iostream>


int main() {
    double n1, n2, n3;
    std::cout << "This program returns the sum of three numbers" << std::endl;

    std::cout << "Input your first number: ";
    std::cin >> n1;

    std::cout << "Input your second number: ";
    std::cin >> n2;

    std::cout << "Input your third number: ";
    std::cin >> n3;

    double sum = n1 + n2 + n3; 

    std::cout << "The sum is " << sum << std::endl;

    return 0;
}