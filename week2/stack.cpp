#include<iostream>
#include<string>
#include<stack>


bool is_matched(std::string expr); 


int main() {

    std::string test1 = "()(()){[()]}";
    std::string test2 = "(())){";

    if (is_matched(test1)) {
        std::cout << test1 << " is corrected" << std::endl; 
        } else {
            std::cout << test1 << " is not corrected " << std::endl; 
        }
    
    if (is_matched(test2)) {
        std::cout << test2 << " is corrected" << std::endl; 
        } else {
            std::cout << test2 << " is not corrected " << std::endl; 
        }

    return 0; 
}


bool is_matched(std::string expr) {
    std::string left = "({[";
    std::string right = ")}]";
    std::stack<char> s; 
    for (char ch: expr) {
        if (left.find(ch) != std::string::npos) {
            s.push(ch);
        } else if (right.find(ch) != std::string::npos) {
            if (s.empty()) return false; 
            if (right.find(ch) != left.find(s.top())) {
                return false; 
                }
            s.pop(); 
        }
    }

    return s.empty(); 
}