#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/x-and-his-shots/
 */

using namespace std;

vector <string> split_string(string);


bool isOverlap(int x1, int x2, int y1, int y2) {
    return (x1 <= y2 && y1 <= x2);
}

template<class ForwardIterator, class T>
int bin_search(ForwardIterator first, ForwardIterator last, const T &val) {
    ForwardIterator low = lower_bound(first, last, val);
    return (low - first);
}

// Complete the solve function below.
int solve(vector <vector<int>> shots, vector <vector<int>> players) {
    int res = 0;
    // naive approach 21.43 points
    // for(auto &&shot : shots){

    //     for(auto &&player : players){
    //         if(isOverlap(shot.front(), shot.back(), player.front(), player.back()) ) {
    //             res++;
    //         }
    //     }

    // }

    vector<int> a, b;

    for (auto &&shot : shots) {

        a.push_back(shot.front()/*A*/);

        b.push_back(shot.back()/*B*/);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto &&player : players) {
        // how many intervals starts before D
        int ad = bin_search(a.begin(), a.end(), player.back() + 1 /*D*/);
        // how many intervals ends after C
        int bc = bin_search(b.begin(), b.end(), player.front() /*C*/);

        // cout << ad << ", " << bc << endl;
        res += ad - bc;
    }


    return res;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector <string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector <vector<int>> shots(n);
    for (int shots_row_itr = 0; shots_row_itr < n; shots_row_itr++) {
        shots[shots_row_itr].resize(2);

        for (int shots_column_itr = 0; shots_column_itr < 2; shots_column_itr++) {
            cin >> shots[shots_row_itr][shots_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector <vector<int>> players(m);
    for (int players_row_itr = 0; players_row_itr < m; players_row_itr++) {
        players[players_row_itr].resize(2);

        for (int players_column_itr = 0; players_column_itr < 2; players_column_itr++) {
            cin >> players[players_row_itr][players_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = solve(shots, players);

    fout << result << "\n";

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
