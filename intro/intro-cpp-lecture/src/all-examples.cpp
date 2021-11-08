/* All Examples from Introduction to C++ Lecture
 * Note: this project will compile with warnings about
 * unused variables.
 */

// slide 5: #include statements
#include <iostream>
#include <cmath>
#include "console.h"
#include "all-examples.h"
#include "testing/SimpleTest.h"

using namespace std;

// functions that main uses:

int factorial(int number) {
    int result = 1;
    for (int n = number; n > 1; n--) {
        result *= n;
    }
    return result;
}

void printTenTimes(char c) {
    for (int i = 0; i < 10; i++) {
        cout << c;
    }
    cout << endl;
}

int doubleValue(int x) {
    x *= 2;
    return x;
}

void doubleValueWithRef(int &x) {
    x *= 2;
}

int square(int x) {
    return x * x;
}

bool even(int v) {
    return v % 2 == 0;
}

PROVIDED_TEST("Some provided tests."){
    EXPECT_EQUAL(factorial(1), 1);
    EXPECT_EQUAL(factorial(2), 2);
    EXPECT_EQUAL(factorial(3), 6);
    EXPECT_EQUAL(factorial(4), 24);
}

