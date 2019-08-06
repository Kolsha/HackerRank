#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/cipher/
 */

using namespace std;

vector <string> split_string(string);

char cxor(char a_c, char b_c) {
    int a = a_c - '0';
    int b = b_c - '0';
    return ((a ^ b) & 1) ? '1' : '0';
}

// Complete the cipher function below.
string cipher(int n, int k, string s) {
    string res(n, '0');
    for (int i = 0; i < n; i++) {

        if (i == 0)
            res[0] = s[0];
        else if (i < k)
            res[i] = cxor(s[i], s[i - 1]);
        else
            res[i] = cxor(cxor(s[i], s[i - 1]), res[i - k]);
    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector <string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = cipher(n, k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector <string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector <string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
