#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/lilys-homework/
 */

using namespace std;

vector <string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr_orig) {
    int result = INT_MAX;


    vector<int> sorted(arr_orig);
    sort(sorted.begin(), sorted.end(), greater<int>());

    for (int rev = 0; rev < 2; rev++) {
        int curSwap = 0;
        if (rev) {
            reverse(sorted.begin(), sorted.end());
        }
        vector<int> arr(arr_orig);
        // val, pos
        unordered_map<int, int> val2pos;
        for (int i = 0; i < arr.size(); i++) {
            val2pos[arr[i]] = i;
        }


        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == sorted[i]) {
                continue;
            }
            int ai = arr[i];
            int si = sorted[i];

            swap(arr[i], arr[val2pos[si]]);
            curSwap++;


            val2pos[ai] = val2pos[si];
            val2pos[si] = i;


        }

        result = min(result, curSwap);

    }


    return result;


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector <string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
