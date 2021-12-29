/*
Implement Queue based on linked list 
*/
#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H
#include<iostream>


template <typename T>
class QueueLinked {
    public:
        QueueLinked();  
        ~QueueLinked();
        int size() const;
        bool is_empty() const;
        void enqueue(T value);  // enqueue 
        T dequeue();
        void clear(); // clear all elements
        T peek_head() const;
        T peek_tail() const; 
    private:
        // class within the class 
        struct Node
        {
            T data; 
            Node *link;
        };
        // instance 
        Node *head;  // instance are pointer that points to node, works as an index 
        Node *tail;   // tail pointer works as an index 
        int count; 

}; 


template <typename T>
QueueLinked<T>::QueueLinked() {
    head = tail = nullptr;
    count = 0;
}


template <typename T>
QueueLinked<T>::~QueueLinked() {
    clear();
}


template <typename T>
int QueueLinked<T>::size() const {
    return count; 
}


template <typename T>
bool QueueLinked<T>::is_empty() const {
    return count == 0;
}


template <typename T>
void QueueLinked<T>::clear() {
    while (count > 0){
        dequeue();
    }
}


template <typename T>
void QueueLinked<T>::enqueue(T value) {
    Node *new_node = new Node; 
    new_node->data = value;
    new_node->link = nullptr;  // the tail always point to a null pointer 
    if (head == nullptr) {
        head = new_node;
    } else {
        tail->link = new_node;  // link the current tail to the new node 
    }
    tail = new_node;  // use new_node as tail (index)
    count++;
}


template <typename T>
T QueueLinked<T>::dequeue() {
    if(is_empty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node *temp = head;
    T result = temp->data;
    head = temp->link;
    if (head == nullptr) tail = nullptr;
    delete temp;
    count --;
    return result;
}


template <typename T>
T QueueLinked<T>::peek_head() const {
    if(is_empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return head->data;
}


template <typename T>
T QueueLinked<T>::peek_tail() const {
    if(is_empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return tail->data;
}








#endif