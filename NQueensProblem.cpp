/* Anthony Jerez-Tenecela (Assignment: NQueens Problem) */
#include <iostream>
using namespace std;
bool ok (int q[], int c) {
    // returns true if the current configuration passes the row and up/down diagonal tests
    for (int i = 0; i < c; i++) {
        if (q[i] ==  q[c] || (c - i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

int nqueens (int n) {
    int solutions = 0, c = 0;
    int *q = new int[n]; // allocates dynamic memory to create an array of size n
    q[c] = 0;
    // ends the loop once c backtracks from the first column 
    while (c >= 0) {
        c++; // moves to the next column
        // if c exceeds the last column, then we found a solution and backtrack to look for more potential solutions
        if (c == n) { 
            solutions++;
            c--;
        }
        else q[c] = -1; // to start in the first row, set q[c] equal to -1
        // ends the loop once c bracktracks from the first column
        while (c >= 0) {
            q[c]++; // moves to the next row
            // if q[c] exceeds the last row, we backtrack
            if (q[c] == n) {
                c--;
            }
            // Otherwise, call the ok function. If q[c] passes the row and up/down diagonal tests, then we found a queen in the row
            else if (ok(q,c)) {
                break;
            }
        }
    }
    delete[] q; // delete the dynamically allocated memory to prevent a memory leak
    return solutions; // return the number of solutions to the nqueens problem
}


int main() {
    int n = 12;
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}