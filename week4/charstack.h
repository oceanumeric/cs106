/*
Implementation of array based charstack 
Even though those implementations use different data structures, the public
part of the class stays exactly the same!
We need a data sctructure that can expand dynamically as the program runs 
*/
#ifndef CHARSTACK_H
#define CHARSTACK_H
#include<vector>


class CharStack {
    public:
        // default constructor
        CharStack();
        // destructor 
        ~CharStack();

        int size();  // returns the size of char stack 
        bool is_empty();
        void clear();  // clear all elements of char stack 
        void push(char ch);  // push ch into the stack 
        char pop();  // pop out the first char and remove 
        char peek();  // return the top char without removing it 
    private:
        std::vector<char> elements; 
};


#endif