#include <iostream>


int combination(int n, int k);
int fact(int n);


int main() {
    int n, k;
    std::cout << "Enter the number of objects (n): ";
    std::cin >> n;
    std::cout << "Enter the number to be chosen (k): ";
    std::cin >> k;
    std:: cout << "C(n, k) = " << combination(n, k) << std::endl;
}


int combination(int n, int k) {
    return fact(n) / (fact(k) * fact(n-k)); 
}


int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result; 
}