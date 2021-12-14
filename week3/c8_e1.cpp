/*
The Towers of Hanoi 
*/
#include <iostream>


void moveTower(int n, char start, char finish, char temp);
void moveSingleDisk(char start, char finish); 


int main () {
    int n;
    std::cout << "Please enter an integer ";
    std::cin >> n; 
    std::cout << "The number you enter is " << n << std::endl; 
    std::cout << "Now, let's play the tower of Hanoi" << std::endl; 

    moveTower(n, 'A', 'B', 'C'); 

    return 0; 
}


void moveSingleDisk(char start, char finish) {
    std::cout << start << " -> " << finish << std::endl; 
}

void moveTower(int n, char start, char finish, char temp) {
    if (n == 1) {
        moveSingleDisk(start, finish); 
    } else {
        moveTower(n-1, start, temp, finish); 
        moveSingleDisk(start, finish); 
        moveTower(n-1, temp, finish, start); 
    }
}
