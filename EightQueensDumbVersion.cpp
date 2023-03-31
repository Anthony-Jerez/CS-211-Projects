/* Anthony Jerez-Tenecela
Eight Queens 1D Array Dumb Version */

#include <iostream>
using namespace std;

bool testOk (int q[]) {
    // returns false if the array doesn't pass the row and up/down diagonal tests
    for (int c = 7; c > 0; c--) {
        for (int j = 0; j < c; j++) {
            if ((q[c] == q[j]) || (c-j) == abs(q[c] - q[j])) return false;
        }
    }
    /*for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 8; j++) {
            if ((q[j] == q[i]) || (j-i) == abs(q[j] - q[i])) return false;
        }
    }
    */
    
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
    int q[8];
    // i0 (part of outermost loop) is the position of the queen in column #0
    // i7 (part of innermost loop) is the position of the queen in column #7
	// all possible board configurations are being tested
    for (int i0 = 0; i0 <= 7; i0++) {
        for (int i1 = 0; i1 <= 7; i1++) {
            for (int i2 = 0; i2 <= 7; i2++) {
                for (int i3 = 0; i3 <= 7; i3++) {
                    for (int i4 = 0; i4 <= 7; i4++) {
                        for (int i5 = 0; i5 <= 7; i5++) {
                            for (int i6 = 0; i6 <= 7; i6++) {
                                for (int i7 = 0; i7 <= 7; i7++) {
                                    // places eight queens on the chess board
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;
                                    // checks the current configuration by passing it to the testOk function
                                    if (testOk(q)) { 
                                        printArray(q); // if the row and up/down diagonal tests pass, the array is printed
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}