#include <bits/stdc++.h>
/*
 * Difficulty Hard
 * Max Score 50
 * https://www.hackerrank.com/challenges/cube-summation/
 */

using namespace std;


using d3_point = tuple<int, int, int>;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int test_count; // T
    cin >> test_count;

    map<d3_point, long> cube;
    for (int test_id = 0; test_id < test_count; test_id++) {
        int size; // N
        int oper_count; // M
        cin >> size >> oper_count;

        string oper;
        int x1, y1, z1;
        int x2, y2, z2;
        long w;
        for (int oper_id = 0; oper_id < oper_count; oper_id++) {
            cin >> oper;
            if (oper == "UPDATE") {
                cin >> x1 >> y1 >> z1 >> w;
                cube[make_tuple(x1, y1, z1)] = w;
            } else {
                cin >> x1 >> y1 >> z1;
                cin >> x2 >> y2 >> z2;

                long sum = 0;

                for (const auto &kv : cube) {
                    int x, y, z;
                    tie(x, y, z) = kv.first;
                    if (x >= x1 && x <= x2 &&
                        y >= y1 && y <= y2 &&
                        z >= z1 && z <= z2) {
                        sum += kv.second;
                    }
                }
                cout << sum << endl;
            }
        }

        cube.clear();
    }


    return 0;
}
