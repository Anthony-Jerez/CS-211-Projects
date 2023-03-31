/* Anthony Jerez-Tenecela
Stable Marriage - Backtracking */
#include <iostream>
using namespace std;

bool ok(int q[], int c) {
    // declare a 2D array named mp and initialize its contents to each of the three men's preferences from 0-2                          
    static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
    // declare a 2D array named wp and initialize it to each of the three women's preferences from 0-2
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences
    // iterates through each man #i up to man #c
    for (int i = 0; i < c; i++) {
        // if a woman is assigned to more than one man return false
        if (q[i] == q[c]) return false;
        // if man #i prefers man#c's wife more than his own wife and its reciprocated return false
        if ((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c])) return false;
        // if man #c prefers man#i's wife more than his own wife and its reciprocated return false
        if ((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i])) return false;
    }
    return true;
}

void print(int q[]) {
    static int solution = 1;
    // below is the representation of the 1D array
    cout << "Solution #" << solution++ << ":" << endl;
    cout << "Man\tWoman" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << "\t" << q[i] << endl;
    }
    cout << endl;
}

int main() {
    int q[3], c = 0;
    q[c] = 0; // set position 0 equal to 0
    // loop ends once c backtracks from man#0
    while (c >= 0) {
        c++; // moves up to the next man#
        // if c exceeds the last man#, print the configuration and backtrack. Otherwise, set the man's wife number equal to -1
        if (c > 2) {
            print(q);
            c--;
        }
        else q[c] = -1;
        // loops ends once c backtracks from man#0
        while (c >= 0) {
            q[c]++;
            // if the man's wife number is more than 2, backtrack. Otherwise, if the current configuration passes the tests in the ok function break out of the current loop
            if (q[c] > 2) {
                c--;
            }
            else if (ok(q,c)) {
                break;
            }
        }
    }
    return 0;
}