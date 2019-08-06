#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 25
 * https://www.hackerrank.com/challenges/two-strings/
 */

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    unordered_map<char, bool> map1;

    for (auto &&ch : s1) {
        map1.insert({ch, true});
    }

    for (auto &&ch : s2) {
        if (map1.find(ch) != map1.end()) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
