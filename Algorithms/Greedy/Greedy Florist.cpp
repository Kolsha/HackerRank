#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 35
 * https://www.hackerrank.com/challenges/greedy-florist/
 */

using namespace std;

vector <string> split_string(string);

// curval, curBuyes
typedef pair<int, int> ppi;

int getMinimumCost(int k, vector<int> c) {

    priority_queue<int, vector<int>, greater<int> > pq;


    for (int count = 0; count < k; count++) {
        pq.push(1);
    }


    int buyed = 0;
    const int needToBuy = c.size();
    int result = 0;


    while (buyed < needToBuy) {
        int currMul = pq.top();
        pq.pop();


        auto it = max_element(c.begin(), c.end());

        result += *it * currMul;
        buyed++;

//        cout << *it << " with " << currMul << endl;

        *it = 0;

        pq.push(currMul + 1);

    }

    return result;


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector <string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector <string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    fout << minimumCost << "\n";

    fout.close();

    return 0;
}

vector <string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector <string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
