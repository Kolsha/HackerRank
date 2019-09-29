#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 60
 * https://www.hackerrank.com/challenges/jim-and-the-skyscrapers/
 */

using namespace std;

vector <string> split_string(string);

// Complete the solve function below.
long solve(vector<int> arr) {
    long res = 0;
    stack<int> st;
    vector<int> l(arr.size(), -1);

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            l[i] = st.top();
        }

        st.push(i);
        mp[arr[i]].push_back(i);

    }


    // for(auto &&left : l) {
    //     cout << left << "," ;
    // }
    // cout << endl;



    for (auto &&p : mp) {

        auto idxs = p.second;
        if (idxs.size() < 2) {
            continue;
        }

        for (int id1 = 0; id1 < idxs.size();) {
            // int id1 = 0;
            int id2 = id1 + 1;
            long tmp = 0;
            while (id2 < idxs.size() && l[idxs[id1]] == l[idxs[id2]]) {
                id2++;
                tmp++;
            }
            // (n * (n + 1)) / 2 but because sum pairs * 2
            res += tmp * (tmp + 1);
            id1 = id2;
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
