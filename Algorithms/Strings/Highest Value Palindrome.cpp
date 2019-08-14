#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/richie-rich/
 * help this:
 * https://www.hackerrank.com/challenges/richie-rich/forum/comments/175860
 */

using namespace std;

vector <string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {

    int start = 0;
    int end = n - 1;

    int need_chng = 0;
    const int dsz = ((n % 2)) ? 0 : 1;
    while (start < n && end >= 0) {
        if (s[start] != s[end]) {
            need_chng++;
        }
        if ((start + dsz) >= end) {
            break;
        }
        start++;
        end--;
    }
    if (need_chng > k) return "-1";


    int delta = k - need_chng;
    start = 0;
    end = n - 1;
    bool valid = true;

    while (start < n && end >= 0) {
        if (k <= 0) {
            break;
        }

        char max_c = max(s[start], s[end]);
        bool eq = s[start] == s[end];

        if (max_c < '9') {

            if ((eq && delta > 1)) {

                s[start] = '9';
                s[end] = '9';
                delta -= 2;
                k -= 2;
                continue;
            }

            if ((start == end) && eq && delta) {

                s[start] = '9';
                s[end] = '9';
                delta -= 1;
                k -= 1;
                continue;
            }

            if (!eq && delta) {
                s[start] = '9';
                s[end] = '9';
                delta -= 1;
                k -= 1;
                continue;
            }
        }

        if (!eq) {
            k--;
        }

        s[start] = max_c;
        s[end] = max_c;

        if ((start + dsz) >= end) {
            break;
        }
        start++;
        end--;
    }


    return s;
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

    string result = highestValuePalindrome(s, n, k);

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
