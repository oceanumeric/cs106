/*
Implementing priority queue based on array and heap 
*/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<iostream>
#include<string>


// Pdata
struct Pdata
{
    std::string label;
    double priority;  // a smaller value means more urgent 
};


static const int INITIAL_CAPACITY = 10;
// priority queue with a fixed capacity 
class PQArray {
    public:
        // constructor and descructor
        PQArray();
        ~PQArray();

        // methods
        void enqueue(Pdata elem);
        Pdata dequeue();  // dequeue the highest priority one
        Pdata peek() const;  // peek the highest priority one 

        bool is_empty() const; 
        int size() const;
        void clear();

    private:
        Pdata *_parray;
        int _capacity;
        int _count;
};


PQArray::PQArray() {
    _capacity = INITIAL_CAPACITY;
    _parray = new Pdata[_capacity];
    _count = 0;
}

PQArray::~PQArray() {
    delete[] _parray;
}

int PQArray::size() const {
    return _count;
}

bool PQArray::is_empty() const {
    return _count == 0;
}

void PQArray::enqueue(Pdata elem) {
    if(size() == _capacity) {
        throw std::runtime_error("The Priority Queue is FULL !\n");
    }
    // add new value
    _parray[_count] = elem;
    _count++;

    // insertion sort
    for (int i = 0; i < _count; i++) {
        Pdata temp = _parray[i];
        int j = i;
        while (j >= 1 && _parray[j-1].priority > temp.priority) {
            _parray[j] = _parray[j-1];
            j--;
        }
        _parray[j] = temp; 
    }
}


Pdata PQArray::dequeue() {
    if (is_empty()) {
        throw std::runtime_error("The Priority Queue is Empty !\n");
    }
    // return the top priority value and shift the whole array 
    Pdata result = _parray[0];
    for (int i = 1; i < _count; i++) {
        _parray[i-1] = _parray[i];
    }

    _count --; 
    return result;
}

Pdata PQArray::peek() const {
    if (is_empty()) {
        throw std::runtime_error("The Priority Queue is Empty !\n");
    }
    return _parray[0];
}

void PQArray::clear() {
    _count = 0;
}



#endif