#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/contacts/
 */

using namespace std;

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector <vector<string>> queries) {
    /*
     * Write your code here.
     */
    unordered_map <string, size_t> tree;
    vector<int> res;
    for (auto &&q : queries) {
        if (q[0] == "add") {
            for (size_t i = 1; i <= q[1].length(); i++) {
                tree[q[1].substr(0, i)]++;
            }

        } else {
            if (!tree.count(q[1])) {
                res.push_back(0);
            } else {
                res.push_back(tree[q[1]]);
            }
        }
    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
