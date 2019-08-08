#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 25
 * https://www.hackerrank.com/challenges/balanced-brackets/
 */

using namespace std;

bool isOpen(char c) {
    return (c == '(') || (c == '[') || (c == '{');
}


char reverseBracket(char c) {
    switch (c) {
        case '(':
            return ')';
        case ')':
            return '(';

        case '[':
            return ']';
        case ']':
            return '[';

        case '{':
            return '}';
        case '}':
            return '{';
    }
    return '\0';
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    for (auto &&ch : s) {
        if (isOpen(ch)) {
            st.push(ch);
        } else {
            if (st.empty() || reverseBracket(ch) != st.top()) {
                return "NO";
            }
            st.pop();
        }

    }

    return (st.empty()) ? "YES" : "NO";

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
