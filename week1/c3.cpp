/*
Strings
*/
#include <iostream>
#include <string>


void mystery(std::string a, std::string& b); 
void nameDiamond(std::string str);


int main() {
    std::string str = "abc";
    std::cout << "Print the string: " << str << std::endl; 
    str += 'D';  // string concatenation

    if (str == "abcD") {
        std::cout << "The string is " << str << std::endl; 
    }

    std::cout << "The first element of the string is " << str[0] << std::endl; 

    std::string str2;
    std::cout << "Do you want to change the first element to 'H'";
    std::cin >> str2;

    if (str2 == "Yes") {
        str[0] = 'H';
        std::cout << "The string becomes " << str << std::endl; 
    }

    std::cout << "Find the index of 'b' " << str.find('b') << std::endl;

    // iterating through the characters in a string
    for (int i = 0; i < str.length(); i++) {
        std::cout << str[i] << std::endl; 
    }

    // string is mutable 
    std::string a  = "Michael";
    std::string b = "Wang"; 

    mystery(a, b);

    std::cout << a << " " << b << std::endl; 
    std::cout << "a.erase(0, 1) becomes " << a.erase(0, 1) << std::endl; 

    nameDiamond("Michael");

    return 0; 
}


void mystery(std::string a, std::string& b) {
    a.erase(0, 1);  // erase 1 from index 0
    b += a[0];
    b.insert(3, "Foo");  // insert at index 3 
}


void nameDiamond(std::string str) {
    // first half of diamond
    for (int i = 0; i < str.length(); i++) {
        std::cout << str.substr(0, i) << std::endl; 
    }
    // the second half
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << " "; 
        }
        std::cout << str.substr(i+1) << std::endl; 
    }
}