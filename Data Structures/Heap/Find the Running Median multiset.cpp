#include <bits/stdc++.h>
/*
 * Difficulty Hard
 * Max Score 50
 * https://www.hackerrank.com/challenges/find-the-running-median/
 * TODO: using two heap
 */

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
    vector<double> res;
    multiset<int> s;
    auto mid = s.end();
    for (auto &&num : a) {
        // for(auto &&n : s){
        //     cerr << n << ", ";
        // }
        // cerr << "mid = " << *mid << "; " << distance(s.begin(), mid) << endl;

        s.insert(num);
        if (mid == s.end()) {
            mid = s.begin();//next(s.begin(), s.size() / 2);
        }

        if (0 != (s.size() % 2) && *mid > num) {
            mid--;
        }
        if (0 == (s.size() % 2) && *mid <= num) {
            mid++;
        }

        double m = (double(*mid) + *prev(mid, 1 - s.size() % 2)) / 2.0;
        res.push_back(m);

    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << setprecision(1) << fixed << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
