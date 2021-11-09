#include <iostream>
#include <cmath>
#include <iomanip>
#include "simpio.h"
#include "gwindow.h"


void quadratic(int a, int b, int c, double& root1, double& root2);
void drawDiamond(GWindow & gw);


int main() {

    std::cout << "Hello world !" << std::endl;
    int age = getInteger("How old are you?");
    std::cout << "Yeah right! Michael wishes he were " << age << "!" << std::endl;

    // test the quadratic function 
    double root1, root2;
    quadratic(1, -3, -4, root1, root2); 
    std::cout << "The roots are " << root1 << " and " << root2 << std::endl;

    // test draw diamond
    std::cout << "This program draws a diamond, rectangle, and oval." << std::endl;
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.drawLine(0, height / 2, width / 2, 0);
    gw.drawLine(width / 2, 0, width, height / 2);
    gw.drawLine(width, height / 2, width / 2, height);
    gw.drawLine(width / 2, height, 0, height / 2);
    gw.setColor("BLUE");
    gw.fillRect(width / 4, height / 4, width / 2, height / 2);
    gw.setColor("GRAY");
    gw.fillOval(width / 4, height / 4, width / 2, height / 2);

    return 0;
}


void quadratic(int a, int b, int c, double& root1, double& root2) {
    root1 = (-b + sqrt(b*b-4*a*c)) / (2*a);
    root2 = (-b - sqrt(b*b-4*a*c)) / (2*a);
}


void drawDiamond(GWindow & gw) {
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.drawLine(0, height/2, width/2, 0);
    gw.drawLine(width/2, 0, width, height/2);
}