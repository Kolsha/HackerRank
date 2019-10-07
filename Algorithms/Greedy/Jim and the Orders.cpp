#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 40
 * https://www.hackerrank.com/challenges/jim-and-the-orders/
 */

using namespace std;

// Complete the jimOrders function below.
vector<int> jimOrders(vector <vector<int>> orders) {
    vector<int> res;
    multimap<long, int> time;
    for (int i = 0; i < orders.size(); i++) {
        auto &&o = orders[i];
        time.insert({o.front() + o.back(), i + 1});
    }
    for (auto &&p : time) {
        res.push_back(p.second);
    }
    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
