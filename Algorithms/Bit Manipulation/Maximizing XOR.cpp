#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 30
 * https://www.hackerrank.com/challenges/maximizing-xor/
 */

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {


    int result = l ^r;
    for (int a = l; a <= r; a++) {
        for (int b = l; b <= r; b++) {
            int calc = a ^b;
            if (calc > result) {
                result = calc;
            }
        }
    }

    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}
