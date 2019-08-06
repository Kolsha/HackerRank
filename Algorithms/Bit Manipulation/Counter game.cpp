#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/counter-game/
 */

using namespace std;


// Complete the counterGame function below.
string counterGame(long n) {
    size_t turn = 1;
    for (n = n - 1; n != 0; n >>= 1) {
        if (n & 1) {
            turn++;
        }
    }


    if (turn % 2 != 0) {
        return "Richard";
    }
    return "Louise";

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
