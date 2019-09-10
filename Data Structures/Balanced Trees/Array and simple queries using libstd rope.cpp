#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ext/rope>
/*
 * Difficulty Hard
 * Max Score 80
 * https://www.hackerrank.com/challenges/array-and-simple-queries/
 * help this:
 * https://codeforces.com/blog/entry/10355
 * https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a00223.html
 * but because probabilistic sometimes not all tc passed
 * TODO: try to use another impl
 */

using namespace std;
using namespace __gnu_cxx;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rope<int> arr;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        int type, start, stop;
        cin >> type >> start >> stop;
        if (start == 1 && stop == N) {
            continue;
        }
        --start;
        --stop;


        rope<int> cur = arr.substr(start, stop - start + 1);
        arr.erase(start, stop - start + 1);
        if (type == 1) {
            arr.insert(arr.mutable_begin(), cur);
        } else {
            arr.insert(arr.mutable_end(), cur);
        }
    }

    cout << abs(arr.front() - arr.back()) << endl;

    for (auto &&a : arr) {
        cout << a << " ";
    }
    return 0;
}
