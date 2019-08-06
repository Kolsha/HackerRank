#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 20
 * https://www.hackerrank.com/challenges/the-power-sum/
 */

using namespace std;

int myPow(int x, int p) {
    int i = 1;
    for (int j = 1; j <= p; j++) i *= x;
    return i;
}

void pSum(const int x, const int power,
          const int currSum,
          const int currN,
          int &acc
) {

    int curInPower = myPow(currN, power);

    if (currSum == x) {
        acc++;
        return;
    }

    if (currSum > x || curInPower > x) {
        return;
    }

    pSum(x, power, currSum, currN + 1, acc);

    pSum(x, power, currSum + curInPower, currN + 1, acc);
}

// Complete the powerSum function below.
int powerSum(int X, int N) {
    int result = 0;

    pSum(X, N, 0, 0, result);
    return result / 2;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
