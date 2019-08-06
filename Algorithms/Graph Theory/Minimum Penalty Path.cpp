#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/beautiful-path/
 */

using namespace std;

vector <string> split_string(string);

using to_cost = pair<int, int>;

// Complete the beautifulPath function below.
int beautifulPath(int n, vector <vector<int>> edges, int A, int B) {

    vector <vector<bool>> was(n + 1, vector<bool>(1024, false));

    vector <vector<to_cost>> graph(n + 1);


    for (auto &&city : edges) {
        graph[city[0]].push_back({city[1], city[2]});
        graph[city[1]].push_back({city[0], city[2]});
    }

    queue <to_cost> q;
    q.push({0, A});


    was[A][0] = true;


    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int cost = cur.first, v = cur.second;

        for (auto &&e: graph[v]) {
            int new_cost = cost | e.second;
            if (!was[e.first][new_cost]) {
                was[e.first][new_cost] = true;
                q.push({new_cost, e.first});
            }
        }

    }


    for (int i = 0; i < 1024; i++) {
        if (was[B][i]) {
            return i;
        }
    }
    return -1;


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector <string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector <vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector <string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(n, edges, A, B);

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
