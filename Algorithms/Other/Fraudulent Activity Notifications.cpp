#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/
 * help this:
 * https://leetcode.com/problems/sliding-window-median/discuss/96340/on-log-k-c-using-multiset-and-updating-middle-iterator
 */

using namespace std;

vector <string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int res = 0;
    int pos = 0;
    multiset<int> s(expenditure.begin(), expenditure.begin() + d);
    auto mid = next(s.begin(), d / 2);
    for (int i = d; i < expenditure.size(); i++) {

        double m = (double(*mid) + *prev(mid, 1 - d % 2));
        if ((expenditure[i]) >= m) {
            res++;
        }

        s.insert(expenditure[i]);
        if (*mid > expenditure[i]) mid--;

        if (*mid >= expenditure[i - d]) mid++;
        s.erase(s.lower_bound(expenditure[i - d]));

    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector <string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector <string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
