/*
* File: PowersOfTwo.cpp
*/
#include <iostream>
using namespace std;


int raiseToPower(int n, int k);  // function prototype


int main() {
    int limit;
    cout << "This program lists powers of two." << endl;
    cout << "Enter exponent limit: ";
    cin >> limit; 
    for (int i = 0; i <= limit; i++) {
        cout << "2 to the " << i << " = "
             << raiseToPower(2, i) << endl; 
    }

    return 0; 
}


int raiseToPower(int n, int k) {
    int result = 1;
    for (int i = 0; i <= k; i++) {
        result *= n; 
    }

    return result; 
}