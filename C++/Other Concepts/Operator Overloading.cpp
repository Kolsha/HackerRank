#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Difficulty Medium
 * Max Score 25
 * https://www.hackerrank.com/challenges/operator-overloading/
 */
class Matrix {
public:
    vector <vector<int>> a;

    Matrix operator+(const Matrix &other) {
        Matrix res;
        if (a.empty()) return res;
        res.a.resize(a.size(), vector<int>(a.front().size(), 0));
        for (int y = 0; y < a.size(); y++) {
            auto row = a[y];
            for (int x = 0; x < row.size(); x++) {
                res.a[y][x] = a[y][x] + other.a[y][x];
            }
        }
        return res;
    }
};

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
