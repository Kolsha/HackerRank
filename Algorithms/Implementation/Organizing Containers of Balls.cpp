#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/organizing-containers-of-balls/
 */

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector <vector<int>> container) {
    // ball type, count
    unordered_map<int, int> types;
    multiset<int> cnt;
    for (auto &&row: container) {
        int cnt_cap = 0;
        for (int i = 0; i < row.size(); i++) {
            types[i] += row[i];
            cnt_cap += row[i];
        }

        cnt.insert(cnt_cap);

    }
    int n = container.size();
    int count = 0;
    for (auto &&tp: types) {
        int tp_count = tp.second;
        auto got = cnt.lower_bound(tp_count);

        if (got == cnt.end()) return "Impossible";

        cnt.erase(got);
    }

    return "Possible";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector <vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
