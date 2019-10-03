#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/sherlock-and-anagrams/
 */

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> cnt;
    int res = 0;
    for (int len = 1; len < s.length(); len++) {
        for (int i = 0; i <= (s.length() - len); i++) {
            string tmp = s.substr(i, len);
            sort(tmp.begin(), tmp.end());
            cnt[tmp]++;
            // cout << i << ", " << len << endl;
        }
    }

    for (auto &&c : cnt) {
        //n choose 2
        res += (c.second) * (c.second - 1) / 2;
        // cout << c.first<< ", " << c.second << endl;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
