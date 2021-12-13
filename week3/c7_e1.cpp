/*
Chapter 7: Introduction to Recursion 
*/
#include <iostream>
#include <string>


int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1); 
    }
}


int fib(int n) {
    if (n < 2) {
        return n;
    } else {
        return fib(n-1) + fib(n-2); 
    }
}


// checking palindromes
bool is_palindrome (std::string str) {
    int len = str.length();

    if (len <= 1) {
        return true; 
    } else {
        return str[0] == str[len -1] && is_palindrome(str.substr(1, len-2)); 
    }

}


int raise_to_power(int n, int k) {
    if (k == 0) {
        return 1;
    } else {
        return n * raise_to_power(n, k-1); 
    }
}


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b); 
    }
}


std::string reverse(std::string str) {
    int len = str.length();
    if (len == 1) {
        return str.substr(0, 1);
    } else {
        return str[len-1] + reverse(str.substr(0, len-1)); 
    }
}


int main() {

    std::cout << fact(4) << std::endl; 
    std::cout << fib(10) << std::endl; 

    std::string str1 = "noon";
    if (is_palindrome(str1)) {
        std::cout << "string " << str1 << " is palindrome" << std::endl; 
    }

    std::cout << raise_to_power(5, 3) << std::endl; 

    std::cout << "The gcd of 1071, 462 is " << gcd(1071, 462) << std::endl;  

    std::cout << "The reverse of string 'program' is " << reverse("program") << std::endl; 

    std::cout << "The reverse of string 'abcd' is " << reverse("abcd") << std::endl; 

    return 0; 
}