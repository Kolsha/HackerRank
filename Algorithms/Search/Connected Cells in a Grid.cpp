#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/connected-cell-in-a-grid/
 * same as: https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/
 */

using namespace std;

// Complete the connectedCell function below.
vector <vector<bool>> used;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(const vector <vector<int>> &m, int x, int y, int &acc) {

    if (used[y][x] || m[y][x] == 0) return;
    used[y][x] = true;
    acc++;
    for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
        int xn = x + dx[i];
        int yn = y + dy[i];

        if (xn >= m.front().size() || yn >= m.size() || xn < 0 || yn < 0) continue;
        if (used[yn][xn] || m[yn][xn] == 0) continue;

        dfs(m, xn, yn, acc);

    }

}

int connectedCell(vector <vector<int>> matrix) {
    used.resize(matrix.size(), vector<bool>(matrix.front().size(), false));
    int res = 0;
    for (int x = 0; x < matrix.front().size(); x++) {
        for (int y = 0; y < matrix.size(); y++) {
            int acc = 0;
            dfs(matrix, x, y, acc);
            res = max(res, acc);
        }
    }

    return res;

}

int main() {
    // cause problems in input file
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    // cin >> n;
    scanf("%d", &n);
    //  cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    // cin >> m;
    scanf("%d", &m);
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            // cin >> matrix[i][j];
            scanf("%d", &matrix[i][j]);
        }

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);
    printf("%d", result);
    // fout << result;

    // fout.close();

    return 0;
}
