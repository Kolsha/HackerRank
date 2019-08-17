#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 25
 * https://www.hackerrank.com/challenges/gridland-metro/
 * help this:
 * https://www.geeksforgeeks.org/merging-intervals/
 */

using namespace std;

vector <string> split_string(string);
// start, end
using interval = pair<long, long>;

// Complete the gridlandMetro function below.
unsigned long gridlandMetro(int n, int m, int k, vector <vector<int>> track) {
    // row, tracks //
    unordered_map<int, vector<interval> > rows;

    unsigned long result = 0;
    if (k <= 0) return n * m;

    for (auto &&t : track) {
        rows[t[0]].push_back({t[1], t[2]});
    }

    for (auto &&row : rows) {

//        cout << "Row: " << row.first << endl;
        auto &&tracks = row.second;
        sort(tracks.begin(), tracks.end());
        // for(auto &&top : tracks){
        //     cout << "[" << top.first << ", " << top.second << "]" << endl;
        // }

        stack <interval> st;
        st.push(tracks[0]);

        for (int i = 1; i < tracks.size(); i++) {
            auto &&top = st.top();

            if (top.second < tracks[i].first) {
                st.push(tracks[i]);
            } else if (top.second < tracks[i].second) {
                top.second = tracks[i].second;
                st.pop();
                st.push(top);
            }
        }
        long dt = 0;
        while (!st.empty()) {
            auto &&top = st.top();
//            cout << "[" << top.first << ", " << top.second << "]" << endl;

            dt += ((top.second - top.first) + 1);
            st.pop();
        }

        result += m - dt;

    }

    result += (n - rows.size()) * m;

    return result;


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector <string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector <vector<int>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    unsigned long result = gridlandMetro(n, m, k, track);

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
