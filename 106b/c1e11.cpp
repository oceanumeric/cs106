#include <iostream>


int main() {
    double pi = 0; 
    for (int i = 0; i < 20000; i++) {
        double odd = 2 * i + 1; 

        if (i%2 == 0) {
            pi += 1/odd; 
        } else {
            pi -= 1/odd; 
        }
    }
    std::cout << "The approximation of PI is " << pi * 4 << std::endl; 
    return 0; 
}