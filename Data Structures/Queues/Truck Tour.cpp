#include <bits/stdc++.h>
/*
 * Difficulty Hard
 * Max Score 50
 * https://www.hackerrank.com/challenges/truck-tour/
 */

using namespace std;

/*
 * Complete the truckTour function below.
 */
int truckTour(vector <vector<int>> petrolpumps) {
    /*
     * Write your code here.
     */
    long tank = 0;
    int min_idx = 0;

    for (int i = 0; i < petrolpumps.size(); i++) {
        auto &p = petrolpumps[i];
        long delta = p[0] - p[1];
        tank += delta;
        if (tank < 0) {
            tank = 0;
            min_idx = i + 1;
        }

    }

    return min_idx;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
