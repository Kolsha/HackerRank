#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 100
 * https://www.hackerrank.com/challenges/find-maximum-index-product/
 * help this:
 * https://www.geeksforgeeks.org/the-stock-span-problem/
 */

using namespace std;

vector <string> split_string(string);

// Complete the solve function below.
long solve(vector<int> arr) {
    long res = 0;
    vector<int> l(arr.size(), -1);
    stack<int> lst;


    for (int i = 0; i < arr.size(); i++) {
        while (!lst.empty() && arr[lst.top()] <= arr[i]) {
            lst.pop();
        }
        if (!lst.empty()) {
            l[i] = lst.top();
        }
        lst.push(i);
    }

    vector<int> r(arr.size(), -1);
    stack<int> rst;

    for (int i = arr.size() - 1; i > 0; i--) {
        while (!rst.empty() && arr[rst.top()] <= arr[i]) {
            rst.pop();
        }
        if (!rst.empty()) {
            r[i] = rst.top();
        }
        rst.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (l[i] >= 0 && r[i] >= 0) {
            res = max(res, (l[i] + 1L) * (r[i] + 1L));
        }
    }

    return res;


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector <string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    long result = solve(arr);

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
