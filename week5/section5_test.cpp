/*
Reference: https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1222/section/section5/
*/
#include<iostream>
#include "section5.h"


void VFD(int *duncan, int isadora, int& quigley) {
    // -6 2 21 
	isadora += *duncan;  // isadora + duncan -4 
	quigley *= isadora;  // -4 * 21 
	(*duncan) = 1;  // duncan 
	isadora = *duncan;
}


int main() {
    RingBufferQueue rbq; 
    for (int i = 0; i < 5; i++) {
        rbq.enqueue(i+1);
        std::cout << "Ring Buffer Queue enque: " << i+1 << "\n";
    }
    std::cout << "Now we dequeue " << rbq.dequeue() << "\n";
    std::cout << "Now we dequeue " << rbq.dequeue() << "\n";
    std::cout << "The size of ring buffer queue is" << rbq.size() << "\n";
    std::cout << "Now we enqueue 6 \n";
    rbq.enqueue(6);
    std::cout << "The size of ring buffer queue is" << rbq.size() << "\n";
    std::cout << "The front element right now is " << rbq.peek() << "\n";
    rbq.enqueue(7);
    rbq.dequeue();
    std::cout << "The front element right now is " << rbq.peek() << "\n";
    int sunny = -6;
	int klaus = 21;
	int violet = 2;
	VFD(&sunny, violet, klaus);
 	std::cout << sunny << " " << klaus << " " << violet << " \n"; 
    return 0;
}