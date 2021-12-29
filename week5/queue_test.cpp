#include "queue_array.h"
#include "queue_linkedlist.h"
#include <iostream>


int main() {
    // initial capacity = 5
    Queue<int> qi; 
    for (int i = 1; i < 6; i++){
        qi.enqueue(i);
        std::cout << "enqueue: " << i << "\n";
    }
    std::cout << "----------------\n";
    for (int i = 1; i < 3; i++){
        std::cout << "dequeue: " << qi.dequeue() << "\n";
    }
    std::cout << "The size is " << qi.size() << "\n";
    qi.enqueue(9);
    std::cout << "enqueue: " << "9\n";
    qi.enqueue(10);
    std::cout << "enqueue: " << "10\n";
    std::cout << "The size is " << qi.size() << "\n";
    std::cout << "----------------\n";
    for (int i = 1; i < 6; i++){
        // first in first out
        std::cout << "First in Fist out process: " << qi.dequeue() << "\n";
    }

    // test queue based on linked list
    std::cout << "----------------------------\n";
    QueueLinked<char> ql;
    for (char chr = 'A'; chr < 'G'; chr++) {
        std::cout << "enqueue: " << chr << "\n";
        ql.enqueue(chr);
    }

    while (!ql.is_empty()) {
        std::cout << "dequeue: " << ql.dequeue() << "\n";
    }

    return 0;
}
