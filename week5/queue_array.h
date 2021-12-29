/*Implement queue based on array*/
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include <iostream>


/*
To deal with the ring buffer, we have to do modular arithmetic
head: holds the index of the next element to come out of the queue
tail: holds the index of the next free slot 

Assumes capacity = 6;
 0 1 2 3 4 5
|c|.|.|.|a|b|
tail = 1
head = 4
size = (tail + capacity - head) % capacity
     = (1 + 6 - 4) % 6 = 3 
// enqueue E
 0 1 2 3 4 5
|c|.|.|.|a|b|
|c|E|.|.|a|b|
tail = (tail + 1) % capacity
     = (1 + 1) % capacity = 2 

|c|E|F|.|a|b|
expand capaicty = 10
 0 1 2 3 4 5 6 7 8 9 10 11
|c|E|F|.|a|b|.|.|.|.|.|.|; tail = 3, size = 5
when it is close to full size + 1 = capacity, tail should equal size 
tail = count = 5;
tail = (5 + 1) % capacity
     = (5 + 1) % 12 = 6 
 0 1 2 3 4 5 6 7 8 9 10 11
 copy process 
 array[i] = old_array[(head+i) % capacity] 
a|b|c|E|F|G|.|.|.|.|.|; tail = 6, head = 0



*/

static const int INITIAL_CAPACITY = 5;  // easy to test 


template <typename T>
class Queue {

    public:
        Queue();  
        ~Queue();
        int size() const;
        bool is_empty() const;
        void enqueue(T value);  // enqueue 
        T dequeue();
        void clear(); // clear all elements
        T peek_head() const;
        T peek_tail() const; 

    private:
        T *qarray;  // a pointer 
        int capacity; 
        int head;
        int tail;  // tail 
        void expand_capacity();

};


// constructor 
template <typename T>
Queue<T>::Queue(){
    capacity = INITIAL_CAPACITY;
    qarray = new T[capacity];
    head = 0;
    tail = 0;
}


template <typename T>
Queue<T>::~Queue(){
    delete[] qarray;
}


template <typename T>
int Queue<T>::size() const {
    return (tail + capacity - head) % capacity;
}


template <typename T>
void Queue<T>::expand_capacity() {
    int count = size();
    T *old_array = qarray;
    qarray = new T[capacity * 2];
    for(int i = 0; i < count; i++) {
        qarray[i] = old_array[(head+i) % capacity];  // old capacity 
    }
    capacity *=2;  // update capacity now 
    head = 0;
    tail = count; 
    delete[] old_array;

}


template <typename T>
bool Queue<T>::is_empty() const {
    return head == tail;
}


template <typename T>
void Queue<T>::clear() {
    head = tail = 0;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    if (size() == capacity - 1) expand_capacity();
    qarray[tail] = value;  // poinst increment i = 2, j; j = i++; j = 2, i = 3
    tail = (tail + 1) % capacity;
}


template <typename T>
T Queue<T>::dequeue() {
    if (is_empty()) {
        throw std::runtime_error("The Queue is empty");
    }
    T result = qarray[head]; 
    head = (head + 1) % capacity;
    return result;
}


template <typename T>
T Queue<T>::peek_head() const {
    if (is_empty()) {
        throw std::runtime_error("The Queue is empty");
    }
    return qarray[head];
}


template <typename T>
T Queue<T>::peek_tail() const {
    if (is_empty()) {
        throw std::runtime_error("The Queue is empty");
    }
    return qarray[tail-1];
}


#endif