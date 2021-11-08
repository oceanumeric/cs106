#include <iostream>
#include <string>


void non_reference_parameters(int var) {
    var = 0;
}


void reference_parameters(int & var) {
    var = 0; // this will set the variable equal to 0
}


int doubleValue(int x) {
    x *= 2;
    return x;
}


int main() {

    std::string str1 = "Now, we call a function without reference"
                        " parameter non_reference_parameters(x)";
    std::string str2 = "Now, we call a function without reference"
                        " parameter reference_parameters(x)";
    
    std::cout << "This program shows how reference parameters work in C++"
    << std::endl;
    int x = 7;
    std::cout << "The value of x is " << x << std::endl;
    std::cout << str1 << std::endl; 
    non_reference_parameters(x);
    std::cout << "The value of x is " << x << std::endl;
    std::cout << str2 << std::endl; 
    reference_parameters(x);
    std::cout << "The value of x is " << x << std::endl;

    int myValue = 5;
    int result = doubleValue(myValue);

    std::cout << "myValue: " << myValue << " ";
    std::cout << "result: " << result << std::endl; 

    return 0;
}