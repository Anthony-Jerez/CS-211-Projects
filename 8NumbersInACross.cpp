/* Anthony Jerez-Tenecela
8 Numbers In A Cross - Backtracking With 2 While Loops */
#include <iostream>
using namespace std;

bool okay(int q[], int c) {
    // helper array includes the neighbor list for square c
    static int a[8][5] = {
        {-1},            // 0 
        {0, -1},         // 1
        {0, -1},         // 2
        {0, 1, 2, -1},   // 3
        {0, 1, 3, -1},   // 4
        {1, 4, -1},      // 5
        {2, 3, 4, -1},   // 6
        {3, 4, 5, 6, -1} // 7
    };
    // if the number placed inside the square has already been used before return false
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c]) return false; 
    }
    // iterates through each neighbor of square c
    // returns false if the difference between the neighbor and square c is 1
    for (int i = 0; a[c][i] != -1; i++) {
        if (abs(q[c]-q[a[c][i]]) == 1) return false;
    } 
    return true;
}

void print(int q[]) {
    static int solution = 1;
    cout << "Solution#:" << solution++ << endl;
    // below represents the representation of the 1-D Array
    cout << " " << q[0] << q[1] << endl;
    cout << q[2] << q[3] << q[4] << q[5] << endl;
    cout << " " << q[6] << q[7] << endl;
    cout << endl;
}

int main() {
    int q[8], c = 0;
    q[c] = 1; // places number 1 at position 0
    // ends the loop once c backtracks from the first square (first column)
    while (c >= 0) {
        // moves to the next square (next column)
        c++;
        // prints the array and backtracks if c exceeds the last sqaure. Otherwise, set the value of the square equal to 0
        if (c > 7) {
            print(q); 
            c--;
        }
        else q[c] = 0;
        // ends the loop if c backtracks from the first square
        while (c >= 0) {
            // increases the number inside of the square by 1
            q[c]++;
            // if the number inside of the square exceeds 8, then backtrack. Otherwise, if q[c] passes both tests inside the okay function then break out of this loop
            if (q[c] > 8) {
                c--;
            }
            else if (okay(q, c)) {
                break;
            }
        }
    }
    return 0;
}