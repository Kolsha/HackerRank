#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
/*
 * Difficulty Hard
 * Max Score 50
 * https://www.hackerrank.com/challenges/merging-communities/
 * help this:
 * https://www.hackerearth.com/ru/practice/notes/disjoint-set-union-union-find/
 */
using namespace std;

vector<long> size;
vector<long> arr;

long root(long el) {
    while (arr[el] != el) {
        arr[el] = arr[arr[el]]; //path compression
        el = arr[el];
    }
    return el;
}

bool find(long a, long b) {
    return (root(a) == root(b));
}

void union_dsu(long a, long b) {
    long root_a = root(a);
    long root_b = root(b);
    if (root_a == root_b) return;
    if (size[root_a] < size[root_b]) {
        arr[root_a] = arr[root_b];
        size[root_b] += size[root_a];
    } else {
        arr[root_b] = arr[root_a];
        size[root_a] += size[root_b];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long n, q;
    cin >> n >> q;


    size.resize(n + 1, 1);
    arr.resize(n + 1);
    iota(arr.begin(), arr.end(), 0);


    for (int i = 0; i < q; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        char cmd;
        long u, v;
        cin >> cmd;
        if (cmd == 'Q') {
            cin >> u;
            cout << size[root(u)] << endl;
        } else {
            cin >> u >> v;
            union_dsu(u, v);
        }
        

    }
    return 0;
}
