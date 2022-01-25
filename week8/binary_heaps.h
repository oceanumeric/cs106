/*
Use array to build up an implicit tree 
A complete binary tree is a binary tree in which all the levels are completely 
filled except possibly the lowest one, which is filled from the left.
Complete binary tree structure can be implicit instead of storing pointers
Root is at index 0 
Compute neighbors by index arithmetic 
Compute neighbors by index arithmetic:
    left(i) = 2i + 1
    right(i) = 2i + 2
    parent(i) = [(i-1)/2]
Reference:
    https://www.cpp.edu/~ftang/courses/CS241/notes/heap.htm
*/
#ifndef BINARY_HEAPS_H
#define BINARY_HEAPS_H
#include<iostream>

class MaxHeap{
    public:
        MaxHeap();  // constructor 
        ~MaxHeap();  // destructor 
        void insert(int x);
        int get_max();
        int extract_max();  // get max and delete it 
        void print();
    private:
        static const int INITIAL_CAPACITY = 10;  // It is allocated for the lifetime of program

        int capacity;
        int size; 
        int* heap;  // array pointer 

        int left(int i) {return 2*i + 1;}
        int right(int i) {return 2*i + 2;}
        int parent(int i) {return (i-1)/2;}

        void swap(int* x, int* y) {
            // x and y are pointers 
            int temp = *x; 
            *x = *y;
            *y = temp; 
        }

        void expand_capacity() {
            int* old_array = heap;
            capacity *= 2;
            heap = new int[capacity];
            for (int i = 0; i < size; i++) {
                heap[i] = old_array[i];
            }

            delete[] old_array;
        }

        void max_heapify(int i) {
            // in-place 
            int left_child = left(i);
            int right_child = right(i);
            int largest = i;

            // check the bound and whether the left child is larger than the node
            if (left_child <= size && heap[left_child] > heap[largest]) {
                largest = left_child;  // move up 
            }

            if (right_child <= size && heap[right_child] > heap[largest]) {
                largest = right_child;  // move up 
            }

            // now when largest is different from the initival value i
            // it must move up one value then we need to continue to chek 
            // swap the largest node with the current node 
            // and repeat this process until the current node is larger than 
            // the right and the left node
            if (largest != i) {
                swap(&heap[i], &heap[largest]);
                max_heapify(largest);  // do it recursively 
            }
        }

};


MaxHeap::MaxHeap() {
    capacity = INITIAL_CAPACITY;
    size = 0; 
    heap = new int[capacity];
}

MaxHeap::~MaxHeap() {
    size = 0;
    delete[] heap; 
}

void MaxHeap::insert(int x) {
    // if size == capacity, then expand it first
    if (size == capacity) expand_capacity();
    heap[size++] = x;  
    int i = size - 1;  // the last index is size - 1
    while (i != 0 && heap[parent(i)] < heap[i]) {
        // passing by reference 
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i); // update index 
    }
}

int MaxHeap::get_max() {
    return heap[0];
}

int MaxHeap::extract_max() {
    int max_item = heap[0];
    // replace the first one with the last one
    heap[0] = heap[--size];
    // maintain the heap property vai max_heapify();
    max_heapify(0);

    return max_item;
}

void MaxHeap::print() {
    std::cout << "The size is " << size << " and elements are \n";
    for (int i = 0; i < size; i++){
        std::cout << heap[i] << " ";
    }
}




#endif