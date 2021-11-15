/*
Chapter 3 string exercises 
*/
#include <iostream>
#include <string>
#include <cctype>
#include "strlib.h"


std::string capitalize(std::string str);
std::string removeCharacters(std::string str, std::string remove);
std::string replaceAll(std::string str, char c1, char c2);


int main() {

    std::string test_string = "happiness";
    std::string test_suffix = "ment";

    if (endsWith(test_string, test_suffix)) {
        std::cout << test_string << " ends with " << test_suffix << std::endl;
    } else {
        std::cout << test_string << " does not end with " << test_suffix << std::endl;
    }

    std::cout << "capitalize(BOOLEAN) gives " << capitalize("BOOLEAN") << std::endl;
    std::cout << "capitalize(boolean) gives " << capitalize("boolean") << std::endl;
    std::cout << "removeCharacters(counterrevolutionaries, aeiou) gives ";
    std::cout << removeCharacters("counterrevolutionaries", "aeiou") << std::endl;
    std::cout << " replaceAll(nannies, n, d) gives ";
    std::cout <<  replaceAll("nannies", 'n', 'd') << std::endl;
    
    return 0; 
}

std::string capitalize(std::string str) {
    char capital = toupper(str[0]);
    std::string others = "";
    for (int i = 1; i < str.length(); i++) {
        others += str[i];
    }
    others = capital + toLowerCase(others);
    
    return others;
}


std::string removeCharacters(std::string str, std::string remove) {
    for (int i = 0; i < remove.length(); i++) {
        while (str.find(remove[i]) != std::string::npos) {
            int idx = str.find(remove[i]); 
            str.erase(idx, 1);
        }
    }

    return str;
}


std::string replaceAll(std::string str, char c1, char c2) {
    // returns a copy of str with every occurrence of c1
    // replaced by c2
    std::string str2 = str;
    while (str2.find(c1) != std::string::npos) {
        int idx = str2.find(c1); 
        str2[idx] = c2; 
    }

    return str2 ;
}
