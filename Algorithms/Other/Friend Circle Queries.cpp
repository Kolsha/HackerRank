#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 45
 * https://www.hackerrank.com/challenges/friend-circle-queries/
 * help this:
 * https://www.hackerearth.com/ru/practice/notes/disjoint-set-union-union-find/
 */

using namespace std;


unordered_map<int, long> size;
unordered_map<int, long> arr;

long root(long el) {
    if (!arr.count(el)) {
        arr[el] = el;
        size[el] = 1;
    }
    while (arr[el] != el) {
        arr[el] = arr[arr[el]]; //path compression
        el = arr[el];
    }
    return el;
}

bool find(long a, long b) {
    return (root(a) == root(b));
}

long union_dsu(long a, long b) {
    long root_a = root(a);
    long root_b = root(b);
    if (root_a == root_b) return size[root_a];
    if (size[root_a] < size[root_b]) {
        arr[root_a] = arr[root_b];
        size[root_b] += size[root_a];
        return size[root_b];
    } else {
        arr[root_b] = arr[root_a];
        size[root_a] += size[root_b];
        return size[root_a];
    }
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector <vector<int>> queries) {
    vector<int> res;
    int cur_max = 0;
    for (auto &&q : queries) {
        int un = union_dsu(q[0] - 1, q[1] - 1);
        cur_max = max(cur_max, un);
        res.push_back(cur_max);
    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
