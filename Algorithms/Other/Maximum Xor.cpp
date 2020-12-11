#include <bits/stdc++.h>

/*
 * Difficulty Medium
 * Max Score 55
 * https://www.hackerrank.com/challenges/maximum-xor/
 */

using namespace std;

vector <string> split_string(string);

struct bit {
    bit *high = nullptr;
    bit *low = nullptr;

    ~bit() {
        delete high;
        delete low;
    }
};

const int MAX_BIT_CNT = 32;

bool IsBitSet(int num, int bit) {
    return 1 == ((num >> bit) & 1);
}


void insert(bit &b, int val, int pos = MAX_BIT_CNT - 1) {
    const bool high = IsBitSet(val, pos);
    bit **next = &b.low;
    if (high) {
        next = &b.high;
    }

    if (*next == nullptr)
        *next = new bit();

    if (pos == 0) return;

    insert(**next, val, pos - 1);
}

int _xor_(bit &b, int val) {
    int res = 0;
    bit *runner = &b;
    for (int i = MAX_BIT_CNT - 1; i >= 0; i--) {
        const bool high = IsBitSet(val, i);
        if (high) {
            if (runner->low != nullptr) {
                runner = runner->low;
                res = res | (1 << i);
            } else if (runner->high != nullptr) {
                runner = runner->high;
            } else
                break;
        } else {
            if (runner->high != nullptr) {
                runner = runner->high;
                res = res | (1 << i);
            } else if (runner->low != nullptr) {
                runner = runner->low;
            } else
                break;
        }
    }

    return res;
}

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    // solve here
    bit head;
    for (auto &&a : arr)
        insert(head, a);

    vector<int> res;
    res.reserve(queries.size());
    for (auto &&q : queries)
        res.emplace_back(_xor_(head, q));

    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector <string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
