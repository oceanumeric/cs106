#include <iostream>
#include "simpio.h"


int main() {

    std::cout << "Hello world !" << std::endl;
    int age = getInteger("How old are you?");
    std::cout << "Yeah right! Michael wishes he were " << age << "!" << std::endl;
    return 0;
}