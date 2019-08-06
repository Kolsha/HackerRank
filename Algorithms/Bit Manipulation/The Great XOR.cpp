#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 25
 * https://www.hackerrank.com/challenges/the-great-xor/
 */

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {

    long result = 0;

    unsigned int count = 0;
    while (x > 0) {

        if ((x & 1) == 0) {
            result += (1L << count);
        }
        x >>= 1;
        count++;
    }

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
