/* Anthony Jerez-Tenecela
Eight Queens 1D Array With Goto */

#include <iostream>
using namespace std;
int main() {
    int q[8], c = 0, count = 0;
    q[0] = 0;
Nc:
    c++;
    if (c == 8) goto print;
    q[c] = -1;
Nr:
    q[c]++;
    if (q[c] == 8) goto backtrack;
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || ((c-i) == abs(q[c] - q[i]))) goto Nr;
    }
    goto Nc;
backtrack:
    c--;
    if (c == -1) return 0;
    goto Nr;
print:
    cout << "Solution #: " << ++count << endl;
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            if (i != q[j]) cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}