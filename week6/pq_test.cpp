#include<iostream>
#include "priority_queue.h"


int main() {
    PQArray pq;
    Pdata p1{"Marion", 1};
    Pdata p2{"Michael", 2};
    Pdata p3{"Bert", 5};
    Pdata p4{"Zoe", -3};
    pq.enqueue(p1);
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    std::cout << "The size is " << pq.size() << ", and the top priority is: ";
    std::cout << pq.peek().label << " " <<  pq.peek().priority << "\n";
    std::cout << "dequeue the top priority\n";
    Pdata p5 = pq.dequeue();
    std::cout << p5.label << p5.priority << "\n";
    std::cout << "dequeue the top priority again \n";
    pq.dequeue();
    std::cout << "The size is " << pq.size() << ", and the top priority is: ";
    std::cout << pq.peek().label << pq.peek().priority << "\n";
    std::cout << "Enqueue the element {'Hello', 0}\n";
    Pdata p6{"Hello", 0};
    pq.enqueue(p6);
    std::cout << "The size is " << pq.size() << ", and the top priority is: ";
    std::cout << pq.peek().label << " " <<  pq.peek().priority << "\n";
    return 0;
}