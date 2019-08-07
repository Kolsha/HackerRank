#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/ctci-recursive-staircase/
 */

using namespace std;
// curr => val
unordered_map<int, int> cache;

void utilFunc(int curr, const int &max, int &acc) {

    if (curr > max) return;

    if (curr == max) {
        acc++;
        return;
    }

    const int cache_key = max - curr;
    auto got = cache.find(cache_key);
    if (got != cache.end()) {
        acc += got->second;
        return;
    }
    static const int addList[] = {1, 2, 3};
    for (auto &&add : addList) {
        if ((curr + add) <= max) {
            utilFunc(curr + add, max, acc);
        }
    }
    cache.insert({cache_key, acc});


}

// Complete the stepPerms function below.
int stepPerms(int n) {
    int result = 0;
    utilFunc(0, n, result);

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
