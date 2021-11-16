#include <iostream>
#include <iomanip>
#include <cmath>


const double PI = 3.14159267;
const double SPEED_OF_LIGHT = 2.99792458E+8; 
const double FINE_STRUCTURE = 7.2573525E-3; 


void printPreciseTable();


int main() {
    std::cout << std::uppercase << std::right; 
    std::cout << "Default Format: " << std::endl << std::endl; 
    printPreciseTable(); 
    std::cout << std::endl << "Fixed Format: " << std::fixed << std::endl << std::endl; 
    printPreciseTable();
    std::cout << std::endl << "Fixed Format: " << std::scientific << std::endl << std::endl; 
    printPreciseTable();
    return 0; 
}


void printPreciseTable() {
    std::cout << "prec |      pi      |  speed of light  | fine-structure" << std::endl; 
    std::cout << "---- +--------------+------------------+---------------" << std::endl; 
    for (int prec = 0; prec <= 6; prec += 2) {
        std::cout << std::setw(4) << prec << "  |"; 
        std::cout << " " << std::setw(12) << std::setprecision(prec) << PI << " |";
        std::cout << " " << std::setw(16) << std::setprecision(prec) << SPEED_OF_LIGHT << " |";
        std::cout << " " << std::setw(12) << std::setprecision(prec) << FINE_STRUCTURE << std::endl;
    }

}