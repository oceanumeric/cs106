#include <iostream>
#include <string>
#include <cctype>


bool isSentencePalindrome(std::string str); 


int main() {
    
    std::cout << "This program tests for sentence palindromes." << std::endl;
    std::cout << "type stop to terminate the program" << std::endl; 

    while (true) {
        std::string str;
        std::cout << "Please enter a sentence: " ;
        std::getline(std::cin, str); 

        if (str == "stop") break; 

        if (isSentencePalindrome(str)) {
            std::cout << "That sentence is a Palindrome." << std::endl; 
        } else {
            std::cout << "That sentence is not a Palindrome." << std::endl; 
        }

    }

    return 0;
}


bool isSentencePalindrome(std::string str) {

    std::string forward = "";
    std::string backward = ""; 

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            forward += ch;
            backward = ch + backward;
        }
    }

    return forward == backward;
}