#include "charstack.h"
#include<iostream>
#include<vector>


CharStack::CharStack(){
    // leave it empty as we have a private elements initialized 
}


CharStack::~CharStack(){
    // leave it empty too 
}


int CharStack::size() {
    return elements.size();
}


bool CharStack::is_empty() {
    return elements.empty();
}


void CharStack::clear() {
    elements.clear();
}


void CharStack::push(char ch) {
    elements.push_back(ch);
}


char CharStack::pop() {
    if (is_empty()) {
        throw std::runtime_error("The charstack is empty");
    }
    char result = elements[elements.size() - 1];
    elements.erase(elements.end()-1);  // remove the last element 
    return result;

}


char CharStack::peek() {
    if (is_empty()) {
        throw std::runtime_error("The charstack is empty");
    }
    char result = elements[elements.size() - 1];
    return result;
}