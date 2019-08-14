#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/largest-rectangle/
 * help this:
 * similar as https://www.hackerrank.com/challenges/min-max-riddle/
 */

using namespace std;

vector <string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> arr) {
    // complete this function
    //        //val, win_sz
    stack <pair<long, long>> st;
    //          // win_sz , val
    unordered_map<long, long> mp;


    arr.push_back(-1L);
    long max_ws = 0;
    for (auto &&val : arr) {
        long ws = 0;
        while (!st.empty() && st.top().first > val) {
            auto top = st.top();
            ws += top.second + 1;
            if (mp.count(ws)) {
                mp[ws] = max(top.first, mp[ws]);
            } else {
                mp[ws] = top.first;
            }
            st.pop();
        }

        st.push({val, ws});
        max_ws = max(ws, max_ws);
    }

    long res = 0;

    for (auto &&p : mp) {
        res = max(res, p.first * p.second);
    }


    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector <string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
