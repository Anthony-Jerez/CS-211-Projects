/* Anthony Jerez-Tenecela
Eight Queens 1D Array Without Gotos */

#include <iostream>
using namespace std;

bool testOk (int q[], int c) {
    // returns false if the row and up/down diagonal tests fail
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || ((c-i) == (abs(q[c] - q[i])))) return false;
    }
    return true;
}

void printArray (int q[]) {
    static int numbSolutions = 0;
    // increment the number of solutions by 1 everytime an array is printed
    cout << "Solution #" << ++numbSolutions << ": ";
    // prints the values of the array
    for (int i = 0; i <= 7; i++) {
        cout << q[i];
    }
    cout << endl;
    // prints a representation of the array
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            if (i != q[j]) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int q[8], c = 0;
    q[c] = 0;
    // ends the loop once c backtracks from the first column
    while (c >= 0) {
        // moves to the next column
        c++;
        // prints the array and backtracks if c exceeds the last column. Otherwise, set the row equal to -1
        if (c > 7) {
            printArray(q);
            c--;
        }
        else q[c] = -1;
        // ends the loop if c backtracks from the first column
        while (c >= 0) {
            // increment the row by one
            q[c]++;
            // if q[c] exceeds the last row then backtrack. Otherwise, if q[c] passes the row and up/down diagonal tests then break out of this loop
            if (q[c] > 7) {
                c--;
            }
            else if (testOk(q, c)) {
                break;
            }
        }
    }
    return 0;
}