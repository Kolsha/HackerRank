#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/components-in-grap/
 */

using namespace std;

void dfs(
        const int v,
        const vector <vector<int>> &graph,
        vector<bool> &used,
        int &cnt
) {

    used[v] = true;
    for (auto &&u : graph[v]) {
        if (used[u]) continue;
        cnt++;
        dfs(u, graph, used, cnt);
    }
}

/*
 * Complete the componentsInGraph function below.
 */
vector<int> componentsInGraph(vector <vector<int>> gb) {
    /*
     * Write your code here.
     */
//    cout << "START" << endl;
    vector <vector<int>> graph(gb.size() * 2 + 1);
    for (auto &&e : gb) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> used(gb.size() * 2 + 1, false);

    int min_cnt = INT_MAX, max_cnt = 0;
    for (int v = 1; v <= gb.size(); v++) {
        if (used[v]) continue;
//        cout << v << endl;
        int cnt = 1;
        dfs(v, graph, used, cnt);
        if (cnt < 2) continue;
        min_cnt = min(min_cnt, cnt);

        max_cnt = max(max_cnt, cnt);


    }

    return vector<int>({min_cnt, max_cnt});


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
