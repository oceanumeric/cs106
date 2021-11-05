#include <iostream>


int main() {

    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n; 

    while (n != 1) {
        if (n%2 == 0) {
            std::cout << n << " is even, so I divide it by 2 and get "; 
            n = n/2; 
            std::cout << n << std::endl; 
        } else {
             std::cout << n << " is odd, so I multiply by 3 and add 1 to get "; 
            n = n*3 + 1; 
            std::cout << n << std::endl; 
        }
    }
    
    return 0; 
}