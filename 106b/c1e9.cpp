#include <iostream>


bool prime(int n) {
    bool is_prime = true; 
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            is_prime = false; 
        }
    }
    return is_prime;
}

int main () {

    int n = 0; 
    int factor = 1; 
    std::cout << "This program factors a number into products of prime numbers."
              << std::endl; 
    std::cout << "Enter a positive integer to be factored: ";
    std::cin >> n; 
    // find all prime numbers upto n
    for (int i = 2; i < n; i++) {
        if (prime(i)) {
            while (n % i == 0) {
                std::cout << i << std::endl;
                n /= i; 
                if (n == 1) break; 
            }
        }
    }
    std::cout << n << std::endl;
    return 0; 
}