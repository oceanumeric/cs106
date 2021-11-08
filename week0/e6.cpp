// find the largest and the second largest value
#include <iostream>


int main() {
    int n = 0; 
    std::cout << "This program finds the largest and second largest integer"
              << std::endl;
    std::cout << "Enter 0 to stop the programming" << std::endl;
 
    int max = 0; 
    int second_largest = 0; 
    while (true) {
        int value = 0;
        std::cout << "?";
        std::cin >> value;
        if (value >= max) {
            second_largest = max; 
            max = value;
        }
        if (value == 0) break; 
    }
    std::cout << "The largest value is " << max << std::endl;
    std::cout << "The second largest value is " << second_largest << std::endl; 
    return 0; 
}