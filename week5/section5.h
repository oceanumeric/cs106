/* 
Review of memory management
type* variable = new type; // allocate one element
type* variable = new type[n]; // allocate n elements
When you dynamically allocate new resources, it will be available for the 
rest of the program 
*/
#include<iostream>
#include<string>
#include<cmath>


class Circle {
    public:
	// constructs a new circle with the given radius
	    Circle(double r); 
	// returns the area occupied by the circle
	    double area() const;
	// returns the distance around the circle 
	    double circumference() const;

	// returns the radius as a real number
	    double getRadius() const;
	// returns a string representation such as "Circle{radius=2.5}"
	    std::string toString() const;

    private:
        const double pi = 3.14159; 
        double radius; 

};


Circle::Circle(double r) {
    radius = r; 
}


double Circle::area() const {
    return pi * std::pow(radius, 2);
}



double Circle::circumference() const {
    return 2 * pi * radius;
}


double Circle::getRadius() const {
    return radius;
}


std::string Circle::toString() const {
    return  "Circle { radius = " + std::to_string(radius) + "\n";  
}


/*
Class: RingBufferQueue based on array 
*/
static const int INITIAL_CAPACITY = 5; 


class RingBufferQueue {
    // type : int 
    public:
        // constructor and desctructor 
        RingBufferQueue();
        ~RingBufferQueue();
        int size();  // size of elements
        bool is_empty();  // is empty
        bool is_full();  
        void enqueue(int elem);  // Enqueues elem if the queue has room; throws an error if queue is full
        int dequeue();  // 	Returns and removes the element at the front of the queue; throws a string exception if queue is empty
        int peek();  // Returns element at the front of the queue; throws a string exception if queue is empty

    private:
        int capacity;  // with a fixed capacity
        int *array;
        int head;
        int tail; 
        int count;

};


RingBufferQueue::RingBufferQueue() {
    capacity = INITIAL_CAPACITY;  // fixed capacity = 5
    array = new int[capacity];
    head = 0;
    tail = 0;  // the next position to be filled 
    count = 0;
}


RingBufferQueue::~RingBufferQueue() {
    delete[] array; 
}


int RingBufferQueue::size() {
    return count;
}


bool RingBufferQueue::is_empty() {
    return count == 0; 
}


bool RingBufferQueue::is_full() {
    return count == capacity;
}


void RingBufferQueue::enqueue(int elem) {
    if (is_full()) {
        throw std::runtime_error("The RingQueue is full");
    }
    array[tail] = elem;
    tail = (tail+1) % capacity;
    count++;
}


int RingBufferQueue::dequeue() {
    if (is_empty()) {
        throw std::runtime_error("The RingQueue is empty");
    }
    int result = array[head];  // this is important 
    head = (head + 1) % capacity;
    count--;
    return result;
}


int RingBufferQueue::peek() {
    if (is_empty()) {
        throw std::runtime_error("The RingQueue is empty");
    }
    return array[head];
}