#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/zig-zag-sequence/
 */
using namespace std;

void findZigZagSequence(vector<int> a, int n) {
    sort(a.begin(), a.end());
    int mid = (n - 1) / 2; // here
    swap(a[mid], a[n - 1]);

    int st = mid + 1;
    int ed = n - 2; // here
    while (st <= ed) {
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1; // here
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n, x;
    int test_cases;
    cin >> test_cases;

    for (int cs = 1; cs <= test_cases; cs++) {
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a.push_back(x);
        }
        findZigZagSequence(a, n);
    }
}



