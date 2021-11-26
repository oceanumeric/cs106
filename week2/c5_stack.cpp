#include <iostream>
#include <cctype>
#include <string>
#include "error.h"
#include "simpio.h"
#include "stack.h"
#include "strlib.h"


void applyOperator(char op, Stack<double> & operandStack);
void helpCommand(); 


int main() {
    std::cout << "RPN Calculator Simulation (type H for help)" << std::endl;
    Stack<double> operandStack;

    while (true) {
        std::string line = getLine("> "); 
        if (line.length() == 0) line = "Q"; 
        char ch = toupper(line[0]); 
        if (ch == 'Q') {
            break;
        } else if (ch == 'C') {
            operandStack.clear();
        } else if (ch == 'H') {
            helpCommand(); 
        } else if (isdigit(ch)) {
            operandStack.push(stringToReal(line)); 
        } else {
            applyOperator(ch, operandStack); 
        }
    }
    

    return 0; 
}


void applyOperator(char op, Stack<double> & operandStack) {

    double result; 
    double rhs = operandStack.pop(); 
    double lhs = operandStack.pop(); 
    switch (op)
    {
    case '+': result = lhs + rhs; break ;
    case '-': result = lhs - rhs; break ;
    case '*': result = lhs * rhs; break ;
    case '/': result = lhs / rhs; break ;
    
    default:
        error("Illegal operator");
    }

    std::cout << result << std::endl; 
    operandStack.push(result); 

}


void helpCommand() {
    std::cout << "Enter expressions is Reverse Polish Notation, " << std::endl; 
    std::cout << "Q -- Quit the program " << std::endl;
    std::cout << "H -- Disply the help function " << std::endl;
    std::cout << "C -- Clear the calculation stack " << std::endl;
}