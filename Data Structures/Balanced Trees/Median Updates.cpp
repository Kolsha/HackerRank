#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
/*
 * Difficulty Hard
 * Max Score 70
 * https://www.hackerrank.com/challenges/median/
 * help this:
 * https://www.hackerrank.com/challenges/median/forum/comments/438337
 */
using namespace std;

/* Head ends here */

void median(vector<char> cmd, vector<long> X) {

    multiset<long> s;
    auto mid = s.end();
    for (int i = 0; i < X.size(); i++) {

        // for(auto &&n : s){
        //     cerr << n << ", ";
        // }
        // cerr << "mid = " << *mid << "; " << distance(s.begin(), mid) << endl;

        switch (cmd[i]) {
            case 'a':
                s.insert(X[i]);
                if (s.size() == 1) {
                    mid = s.begin();
                } else if (0 == (s.size() % 2) && *mid > X[i]) {
                    --mid;
                } else if (0 != (s.size() % 2) && *mid <= X[i]) {
                    ++mid;
                }


                break;

            case 'r':
                auto it = s.find(X[i]);
                if (it != s.end()) {

                    if (mid == it) {
                        if (s.size() > 1) {
                            if (0 == (s.size() % 2)) {
                                ++mid;
                            } else {
                                --mid;
                            }
                        } else {
                            mid = s.end();
                        }
                    } else {
                        if (0 == (s.size() % 2) && *mid >= *it) {
                            ++mid;
                        }
                        if (0 != (s.size() % 2) && *mid < *it) {
                            --mid;
                        }

                    }


                    s.erase(it);
                } else {
                    cout << "Wrong!" << endl;
                    continue;
                }
                break;
        }


        if (mid == s.end() && s.size()) {
            mid = next(s.begin(), s.size() / 2);
        }


        if (mid != s.end()) {
            double m = (double(*mid) + *next(mid, 1 - (s.size() % 2))) / 2.0;
            cout << setprecision(14) << m << endl;
        } else if (!s.size()) {
            cout << "Wrong!" << endl;
        }


    }

}

int main(void) {

//Helpers for input and output

    int N;
    cin >> N;

    vector<char> s;
    vector<long> X;
    char temp;
    long tempint;
    for (int i = 0; i < N; i++) {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}

