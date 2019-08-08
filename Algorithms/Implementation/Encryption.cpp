#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/encryption/
 */

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    double L = sqrt(s.length());
    int row = floor(L), col = ceil(L);

    if (row == col || (row * col) < s.length())
        row++;

    string res;
    for (int x = 0; x < col; x++) {

        string tmp;
        for (int y = 0; y < row; y++) {
            int pos = y * col + x;
            if (pos < s.length()) {
                tmp += s[pos];
            }
        }
        res += tmp;
        if (x + 1 < col) res += " ";
    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
