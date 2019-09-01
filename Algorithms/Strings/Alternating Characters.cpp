#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 20
 * https://www.hackerrank.com/challenges/alternating-characters/
 */

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int res = 0;
    for (int i = 1; i < s.length(); i++) {
        int prev = i - 1;
        while (i < s.length() && s[prev] == s[i]) {
            i++;
            res++;
        }
    }
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
