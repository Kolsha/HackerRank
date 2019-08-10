#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 35
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/
 */

using namespace std;

vector <string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {

    unordered_multimap<int, size_t> m;

    for (size_t i = 0; i < cost.size(); i++) {
        m.insert({cost[i], i});
    }

    for (size_t i = 0; i < cost.size(); i++) {
        int el = money - cost[i];
        auto p = m.equal_range(el);
        int id = -1;
        for (auto eq = p.first; eq != p.second; ++eq) {
            if (eq->second == i) continue;
            id = eq->second;
            break;
        }
        if (id < 0) continue;

        cout << (i + 1) << " " << (id + 1) << endl;
        break;
    }

}

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector <string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
