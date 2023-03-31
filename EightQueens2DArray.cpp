/* Name: Anthony Jerez-Tenecela
Question: 8 Queens - 2 Dimensional Array Program with Backtracking, GOTO */
#include <iostream>
using namespace std;

int main() {
    int array[8][8] = {}, r, c = 0, counterSolutions = 0;
    array[0][0] = 1;
Nc:
    // moves to the next column
    c++;
    // if c goes outside of the board on right side, display the array solution
    if (c == 8) goto print;
    r = -1;
Nr:
    // moves to the next row
    r++;
    // if r goes outside of the board, backtrack to previous column
    if (r == 8) goto backtrack;
    // checking row
    for (int i = 0; i < c; i++) {
        if (array[r][i] == 1) goto Nr;
    }
    // checking up diagonal 
    for (int i = 1; (r-i) >= 0 && (c-i) >= 0; i++) {
        if (array[r-i][c-i] == 1) goto Nr;
    }
    // checking down diagonal
    for (int i = 1; (r+i) <= 7 && (c-i) >= 0; i++) {
        if (array[r+i][c-i] == 1) goto Nr;
    }
    // place Queen and set Queen position equal to 1
    array[r][c] = 1;
    // refer to the Nc label which moves to the next column
    goto Nc;
backtrack:
    // move back one column
    c--; 
    // terminate progam if c goes outside of the board on the left side
    if (c == -1) {
        return 0;
    }
    r = 0;
    // find the location where there was already a Queen placed and remove it
    while (array[r][c] != 1) {
        r++;
    }
    array[r][c] = 0;
    // look for a next possible location to place the Queen by referring to the Nr label that makes it move to the next row
    goto Nr;
print:
    // display the current solution number 
    cout << "Solution #: " << ++counterSolutions << endl;
    // display the whole board revealing the places where the Queens were placed
    for (int i = 0; i <= 7; ++i) {
        for (int j = 0; j <= 7; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    // backtrack to look for more possible solutions
    goto backtrack;
}