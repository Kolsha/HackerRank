#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 30
 * https://www.hackerrank.com/challenges/cavity-map/
 */

using namespace std;

// Complete the cavityMap function below.
vector <string> cavityMap(vector <string> grid) {
    const int n = grid.size();
    if (n < 3) {
        return grid;
    }
    vector <string> res = grid;

    for (int y = 1; (y + 1) < n; y++) {
        for (int x = 1; (x + 1) < n; x++) {
            char cur = grid[y][x];
            if (grid[y][x - 1] >= cur) continue;
            if (grid[y][x + 1] >= cur) continue;

            if (grid[y - 1][x] >= cur) continue;
            if (grid[y + 1][x] >= cur) continue;
            
            res[y][x] = 'X';
        }
    }
    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector <string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
