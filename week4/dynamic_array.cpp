/*
Using array to represent a stack dynamically 
*/
#include<iostream>


class CharStack {
    private:
        static const int INITIAL_CAPACITY = 10;  // It is allocated for the lifetime of program
        char *char_array;  // dynamic array of characters
        int capacity;
        int count; 

        void expand_capacity();  // expand capacity dynamically 

    public:
        CharStack();  // default constructor 
        ~CharStack();  // default destructor 
        int size() const;
        bool is_empty() const;
        void clear();  // clear the char stack 
        void push(char chr);  // push 
        char pop();  // pop out
        char peek() const;  // peek
};


// constructor 
CharStack::CharStack(){
    capacity = INITIAL_CAPACITY;
    char_array = new char[capacity];  // allocate char memory from heap 
    count = 0; 
}


CharStack::~CharStack(){
    delete[] char_array;
}


void CharStack::expand_capacity(){
    char *old_array = char_array;
    capacity *= 2;
    char_array = new char[capacity];
    for (int i = 0; i < count; i++){
        char_array[i] = old_array[i];
    }

    delete[] old_array;
}


int CharStack::size() const{
    return count; 
}


bool CharStack::is_empty() const{
    return count == 0;
}


void CharStack::clear(){
    count = 0; 
}


void CharStack::push(char chr){
    if (count == capacity) expand_capacity();
    char_array[count++] = chr; 
}


char CharStack::pop(){
    if (is_empty()){
        throw std::runtime_error("The char stack is empty");
    }
    return char_array[--count];  // this is crucial 
}


char CharStack::peek() const{
    if (is_empty()){
        throw std::runtime_error("The char stack is empty");
    }
    return char_array[count - 1];  // 
}


// test 
int main(){
    CharStack cstk; 
    for (int i = 0; i < 26; i++){
        cstk.push(char('A'+i));
    }
    while(!cstk.is_empty()){
        std::cout << cstk.size() << " " << cstk.pop() << "\n";
    }
    return 0;
}
