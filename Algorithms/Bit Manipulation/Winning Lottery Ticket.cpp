#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/winning-lottery-ticket/
 */

using namespace std;

// Complete the winningLotteryTicket function below.
long long winningLotteryTicket(vector <string> tickets) {
    unordered_map<bitset<10>, long> bsm;
    // for special case
    bitset<10> all_ones(ULLONG_MAX);
    bsm[all_ones] = 0;

    for (auto &&t : tickets) {
        bitset<10> bs;
        for (auto &&c : t) {
            bs[c - '0'] = true;
            if (bs.all()) break;
        }
        bsm[bs]++;
    }

    // count of pairs n * (n - 1) / 2
    long long res = bsm[all_ones] * (bsm[all_ones] - 1) / 2;
    unordered_map < bitset < 10 > , long > ::iterator
    it = bsm.begin();
    while (it != bsm.end()) {
        unordered_map < bitset < 10 > , long > ::iterator
        runner = it;
        runner++;
        while (runner != bsm.end()) {
            if ((it->first | runner->first).all()) {
                res += it->second * runner->second;
            }
            runner++;
        }
        it++;
    }

    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <string> tickets(n);

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);

        tickets[i] = tickets_item;
    }

    long long result = winningLotteryTicket(tickets);

    fout << result << "\n";

    fout.close();

    return 0;
}
