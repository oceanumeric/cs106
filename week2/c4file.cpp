#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::ifstream myfile("shakespeare.txt"); 
    std::string line;
    int line_num = 0; 
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            if (line_num == 100) {
                std::cout << "This is the 1000th line: ";
                std::cout << line << std::endl; 
            }
            line_num += 1; 
        }
        myfile.close();
    } else {
        std::cout << "Unable to open the file" << std::endl; 
    }

    std::ofstream outfile("hello.txt");
    outfile << "This is to write a line into a text";
    outfile.close(); 

    return 0; 
}