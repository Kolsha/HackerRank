#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/special-palindrome-again/
 */

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long res = n;
    vector <pair<char, long>> pairs;
    long seq = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            seq++;
            res += seq;
        } else {
            pairs.push_back({s[i - 1], seq + 1});
            seq = 0;
        }
    }
    pairs.push_back({s[n - 1], seq + 1});


    // for(auto &&p : pairs){
    //     cout << p.first << " -> " << p.second << endl;
    // }
    // cout << "Calc" << endl;
    for (size_t i = 0; i < pairs.size(); i++) {
        if ((i + 2) >= pairs.size()) break;
        // cout << pairs[i].first << " -> " << pairs[i].second << endl;

        if (pairs[i + 1].second > 1) continue;

        if (pairs[i + 2].first == pairs[i].first) {
            res += min(pairs[i + 2].second, pairs[i].second);
        }
    }


    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
