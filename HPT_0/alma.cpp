#include <iostream>
using namespace std;

void proba(int ertek, int* cim, int& ref, int kaloz) {
    ertek = 13;
    *cim = 12;
    ref = 9;
    kaloz = 44;  // Modify the value pointed to by dd
}

int main() {
    int korte = 6, alma = 5, meggy = 3;
    int* banan = new int;  // Dynamically allocate memory for xdd
    *banan = 2;            // Set the initial value to 2

    proba(korte, &alma, meggy, *banan);  // Call the function

    cout << "korte: " << korte << endl;   // korte: 6 (unchanged, passed by value)
    cout << "alma: " << alma << endl;     // alma: 12 (changed, passed by pointer)
    cout << "meggy: " << meggy << endl;   // meggy: 9 (changed, passed by reference)
    cout << "xdd:  " << *banan << endl;     // xdd: 44 (changed, passed by pointer)

    delete banan;  // Clean up the dynamically allocated memory
    return 0;
}