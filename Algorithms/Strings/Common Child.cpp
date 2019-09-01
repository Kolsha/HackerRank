#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 60
 * https://www.hackerrank.com/challenges/common-child/
 * help this:
 * https://ru.wikipedia.org/wiki/Наибольшая_общая_подпоследовательность
 */

using namespace std;
constexpr size_t MAX_LENGTH = 5000;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    vector <vector<int>> c(MAX_LENGTH + 1, vector<int>(MAX_LENGTH + 1, 0));

    for (size_t i1 = 0; i1 < s1.length(); i1++) {
        for (size_t i2 = 0; i2 < s2.length(); i2++) {
            if (s1[i1] != s2[i2]) {
                c[i1 + 1][i2 + 1] = max(c[i1 + 1][i2], c[i1][i2 + 1]);
            } else {
                c[i1 + 1][i2 + 1] = c[i1][i2] + 1;
            }
        }
    }


    return c[s1.length()][s2.length()];

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
