/*
Exercises for chapter 1 
*/
#include <iostream>


float cel_to_fah(float cel); 
float meter_to_feet(float meter); 


int main () {

    float cel;
    std::cout << "Please type in the temperature in Celsius: "; 
    std::cin >> cel; 
    std::cout << "The temperature in Fahrenheit is " << cel_to_fah(cel)
              << std::endl; 
    // check the difference
    std::cout << "9/5 is " << 9/5 << std::endl;
    std::cout << "9.0/5.0 is " <<  9.0/5.0 << std::endl;
    std::cout << "9/5 * 1.6 is " << 9/5*1.6 << std::endl;
    std::cout << "9 * 1.6 / 5 is " << 9*1.6/5 << std::endl;

    float meters; 
    std::cout << "Please type in the distance in meters: "; 
    std::cin >> meters; 
    std::cout << meter_to_feet(meters);

    return 0;
}


float cel_to_fah(float cel) {
    // convert celsius to fahrenheit
    float fah = (9.0/5.0*cel) + 32; 
    return fah;
}


float meter_to_feet(float meter) {

    int foot = 0;
    float inch = 0.0; 

    if ( meter/(12 * 0.0254) >= 1.0) {
        // do not declare the variable again
        foot = meter/(12 * 0.0254);
        inch = (meter/(12 * 0.0254) - foot)*12;
    } else {
        foot = 0;
        inch = meter/(12 * 0.0254);
    }

    std::cout << "The distance is " << foot << " foot and " << inch << " inches"
              << std::endl;

    return 0.0;
}