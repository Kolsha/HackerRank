#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 20
 * https://www.hackerrank.com/challenges/climbing-the-leaderboard/
 */

using namespace std;

vector <string> split_string(string);

// Complete the climbingLeaderBoard function below.
vector<int> climbingLeaderBoard(vector<int> scores, vector<int> alice) {
    vector<int> result;
    set<int> s;
    int prev = 0;
    for (auto &&score : scores) {
        if (score == prev) {
            continue;
        }
        s.insert(score);
        prev = score;
    }

    int total_size = s.size();

    for (auto &&a : alice) {
        auto it = s.upper_bound(a);
        int dst = distance(s.begin(), it);

        result.push_back(total_size - dst + 1);
        s.erase(s.begin(), it);
        total_size -= dst;

    }

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector <string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector <string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderBoard(scores, alice);

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
