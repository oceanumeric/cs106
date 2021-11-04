#include <iostream>


const int STOP = 0; 


int main() {
    std::cout << "This program adds a list of integers" << std::endl;
    std::cout << "We use "
              << STOP << " to signal the programmign to stop" << std::endl;
    
    int total = 0;

    while (true) {
        int value;
        std::cout << "?";
        std::cin >> value;

        if (value == STOP) break;
        total += value;
    }

    std::cout << "The total is " << total << std::endl;

    return 0; 
}