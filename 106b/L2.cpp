/*
Code for lecture 2
*/
#include <iostream>
#include <string>
using namespace std;

void myfun() {
    cout << "This is my first function" << endl;
}

void mystring() {
    char s2[] = "ab";  // the original string type
    string s = "ab";
    s += "cd"; 
    cout << s << endl; 
    string name = "Donald Knuth";
    if (name.find("Knu") != string::npos) {
    name.erase(5, 6);
    }

    string str2 = "(babalhsd=--s)";
    string str2_inside = str2.substr(str2.find("(")+1, str2.find(")")-1);
    cout << name << endl; 
    cout << str2_inside << endl;
}

int main() {
    myfun();
    cout << "Hello, world!" << endl; 
    cout << "I love Marion" << endl;
    mystring();
    return 0;
}
