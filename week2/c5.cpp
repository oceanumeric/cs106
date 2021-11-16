/*
Collections: vectors, grid (or matrix), maps (dictionary), set 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "vector.h"


void printVector(Vector<int> & vec); 
int countAlphabetFreq(std::ifstream & textfile); 


int main() {
    // a zero vector
    Vector<int> vec0(7, 0); 
    printVector(vec0); 

    // add elements
    vec0.add(36); 

    // insert value 
    vec0.insert(2, 9); 

    printVector(vec0); 

    // convert a vector to a string 
    std::cout << vec0.toString() << std::endl; 

    // print out the 
    std::cout << "B-A = " << 'B'-'A' << "H-A = " << 'H' - 'A' <<  std::endl; 

    // read a file and calculate the frequency
    std::ifstream input("shakespeare.txt"); 

    countAlphabetFreq(input); 

    // a char vector
    Vector<char> v1 = {'A', 'B', 'C'}; 
    
    std::cout << "[";
    for (int i = 0; i < v1.size(); i++) {
        if (i > 0) std::cout << ",";
        std::cout << v1[i];
    }
    std::cout << "]" << std::endl;

    return 0; 
}


void printVector(Vector<int> & vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) std::cout << ",";
        std::cout << vec[i];
    }
    std::cout << "]" << std::endl; 

}


int countAlphabetFreq(std::ifstream & textfile) {
    Vector<int> letter_counts(26); 
    char ch;
    if (textfile.is_open()) {
        while (textfile.get(ch)) {
            if (isalpha(ch)) {
                letter_counts[toupper(ch) - 'A']++; 
            }
        }
        textfile.close();
    } else {
        std::cout << "Unable to open the file" << std::endl; 
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        std::cout << std::setw(7) << letter_counts[ch - 'A'] << " " << ch << std::endl; 
    }

    return 0; 
}