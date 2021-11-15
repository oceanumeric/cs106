#include <iostream>
#include <string>
#include <cctype>


std::string addCommas(std::string digits);


int main() {
    while (true) {
        std::string digits;
        std::cout << "Enter a number: ";
        std::getline(std::cin, digits); 

        if (digits == "") break; 

        std::cout << addCommas(digits) << std::endl; 
    }

    return 0;
}


std::string addCommas(std::string digits) {

    std::string str=""; 

    int n = digits.length(); 
    int idx = 0;
    
    for (int i = n; i >= 0; i--) {

        char ch = digits[i];
        str = ch + str;

        if (idx % 3 == 0 && idx != 0) {
            str = ',' + str; 
        }

        idx += 1; 

    }

    return str;
}