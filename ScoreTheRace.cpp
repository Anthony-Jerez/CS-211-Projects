#include <iostream>
using namespace std;

int main(){
    while (true) {
        string s = "";
        cout << "Enter the race outcome: ";
        cin >> s;
        if (s == "done") return 0;
        int teamCount[26] = {};
        int count = 0;
        bool Ok = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[0]) count++;
            char c = s[i];
            c -= 65;
            teamCount[c]++;
        }
        for (int i = 0; i < 26; i++) {
            if (teamCount[i] != 0 && teamCount[i] != count) Ok = false;
        }
        if (Ok == false) continue;
        double teamScore[26] = {};
        int numTeams = 0;
        for (int i = 0; i < 26; i++) {
            if (teamCount[i] > 0) numTeams++;
        }
        cout << "There are " << numTeams << " teams.\nEach team has " << count << " runner(s)" << endl;
        for (int i = 1; i <= s.length(); i++) {
            char a = s[i-1];
            a -= 65;
            for (int j = 0; j < 26; j++) {
                if (a == j) teamScore[j] += i;
            }
        }
        cout << "Team\tScore" << endl;
        for (int i = 0; i < 26; i++){
            if (teamScore[i] > 0){
                teamScore[i] = teamScore[i]/(double) count;
                cout << (char) (i+65) << "      " << teamScore[i] << endl;
            }
        }
        double winningScore = teamScore[0];
        for (int i = 1; i < 26; i++){
            if (teamScore[i] > winningScore) winningScore = teamScore[i];
        }
        int team;
        for (int i = 0; i < 26; i++){
            if ((teamScore[i] < winningScore) && (teamScore[i] != 0)) {
                winningScore = teamScore[i];
                team = i + 65;
            }
        }
        cout << "The winning team is team " << (char) team << " with a score of " << winningScore << endl;
    }
}