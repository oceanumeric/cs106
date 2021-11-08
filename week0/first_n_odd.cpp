// calculate the sum of the irst n odd numbers
#include <iostream>


int main() {
    int n = 0;
    int sum = 0; 
    int odd = 1; 

    std::cout << "Please enter an integer"; 
    std::cin >> n; 

    for (int i = 1; i <= n; i++) {
        sum = sum + odd; 
        odd += 2; 
    }

    std::cout << "The sum of the first " << n << " odd numbers is " << sum
              << std::endl;

    return 0;
}