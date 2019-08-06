#include <bits/stdc++.h>
/*
 * Difficulty Easy
 * Max Score 25
 * https://www.hackerrank.com/challenges/ctci-making-anagrams/
 */

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int result = 0;
    vector<int> count(('z' - 'a') + 1);

    for (auto &&ch : a) {
        count[ch - 'a']++;
    }

    for (auto &&ch : b) {
        count[ch - 'a']--;
    }

    for (auto &&num : count) {
        result += abs(num);
    }


    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
