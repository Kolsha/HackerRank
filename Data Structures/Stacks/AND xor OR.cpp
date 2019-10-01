#include <bits/stdc++.h>
/*
 * Difficulty Hard
 * Max Score 70
 * https://www.hackerrank.com/challenges/and-xor-or/
 * help this: https://www.hackerrank.com/challenges/and-xor-or/forum/comments/172421
 */
using namespace std;

vector <string> split_string(string);

/*
 * Complete the andXorOr function below.
 */

long sfunc(int m1, int m2) {
    return (~m1 & m2) | (m1 & ~m2); // m1 ^ m2 equal to
}

int andXorOr(vector<int> a) {
    /*
     * Write your code here.
     */
    long s_max = 0;
    stack<int> st;
    for (auto &&n : a) {
        while (!st.empty()) {
            s_max = max(s_max, sfunc(n, st.top()));
            if (n < st.top()) {
                st.pop();
            } else {
                break;
            }
        }
        st.push(n);
    }
    return s_max;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector <string> a_temp = split_string(a_temp_temp);

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    int result = andXorOr(a);

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
