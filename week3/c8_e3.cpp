/*
string permutation 
*/
#include <iostream>
#include <string>
#include <set>


std::set <std::string> generateStringPermutation(std::string str); 


int main () {
    std::cout << "Please enter the string you want to generate permutation "; 
    std::cout << "such as 'abcd' : "; 
    std::string ss; 
    std::cin >> ss; 
    std::cout << "Your permutation is {"; 
    for (auto elem : generateStringPermutation(ss)) {
        std::cout << elem << " "; 
    }
    std::cout << "}" << std::endl; 

    return 0; 
}


// string.erase(position)
// if you want to remove some character
// include algorithm 
// string.erase(remove(string.being(), string.end(), 'A'))
std::set <std::string> generateStringPermutation(std::string str) {
    std::set <std::string> result; 
    if (str.length() == 1) {
        // base case - only one string
        result.insert(str);
        return result; 
    } else {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i]; 
            std::string temp = str.substr(0, i) + str.substr(i+1); 
            for (auto elem : generateStringPermutation(temp)) {
                result.insert(ch + elem); 
            }
        }
    }

    return result; 
}