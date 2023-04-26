/* Anthony Jerez-Tenecela
Towers of Hanoi (non-recursive) */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n; // n is the number of rings to move 
    cout << endl;
    // if n is odd, then the number of places necessary to move to the "closest" tower is one to the right. Otherwise, if even, the places necessary is two to the right.
    // if n is odd, then the number of places necessary to move to the "furthest" tower is two to the right. Otherwise, if even, the places necessary is one.
    int close = (n % 2 == 1 ? 1 : 2), far = (n % 2 == 1 ? 2 : 1);
    int from = 0, to = close, candidate = 1, move = 0;
    // initalize the first tower to contain the rings to move along with a placeholder value that isn't counted as a ring
    for (int i = n + 1; i >= 1; --i) {
        t[0].push_back(i);
    }
    // initalize the second and third tower to contain a placeholder value which is not counted as a ring
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    // while the second tower doesn't contain all of the rings
    while (t[1].size() < n+1) {
        cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << endl;
        // moves the ring from the "from" tower to the "to" tower
        // once moved, the value is erased from the "from" tower
        t[to].push_back(candidate);
        t[from].pop_back();
        // set "from" to be the index of the tower that contains the smallest top ring that wasn't used in the previous move
        if (t[(to+1) % 3].back() > t[(to+2) % 3].back()) {
            from = (to+2) % 3;
        }
        else from = (to+1) % 3;
        // candidate is the ring on top of the "from" tower
        candidate = t[from].back();
        // set "to" to be the index of the closest tower that the candidate can be moved to 
        if (candidate > t[(from+close) % 3].back()) {
            to = (from+far) % 3;
        }
        else to = (from+close) % 3;
    }
    return 0;
}