#include<iostream>
#include<string>
#include<vector>
#include "stringmap.h"


int main() {
    // test hash function 
    std::vector<std::string> v1 {"a", "A", "Hello"};
    for (std::string elem : v1) {
        std::cout << elem << " has the ash code: " << hash_code(elem) << "\n";
    }
    
    // test string map
    StringMap sm; 
    sm.put("hello", "world");
    sm.put("Michael", "Wang");
    sm.put("s1", "1s");
    std::cout << "---------------------\n";
    std::cout << sm.get("hello") << "\n";
    std::cout << sm.get("Michael") << "\n";
    std::cout << sm.get("s1") << "\n";

    return 0;
}