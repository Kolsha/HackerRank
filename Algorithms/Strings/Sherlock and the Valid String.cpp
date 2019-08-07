#include <bits/stdc++.h>
#include <cmath>
/*
 * Difficulty Medium
 * Max Score 35
 * https://www.hackerrank.com/challenges/sherlock-and-valid-string/
 */

using namespace std;

#define ALPHA_SIZE 'z' - 'a' + 1

// Complete the isValid function below.
string isValid(string s) {
    size_t count[ALPHA_SIZE] = {0};

    for (auto &&c: s) {
        size_t key = c - 'a';
        count[key]++;
    }

    size_t min_fr = numeric_limits<size_t>::max();
    size_t max_fr = 0;

    unordered_map <size_t, size_t> map;
    for (auto &&cnt : count) {
        if (!cnt) continue;
        min_fr = min(min_fr, cnt);
        max_fr = max(max_fr, cnt);
        map[cnt]++;
    }

    if (map.size() > 2) return "NO";

    if (min_fr == max_fr) return "YES";

    if (map[min_fr] == 1) return "YES";

    if (map[max_fr] == 1 && (max_fr - 1) == min_fr) return "YES";


    return "NO";

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
