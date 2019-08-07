#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/journey-to-the-moon/
 */

using namespace std;

vector <string> split_string(string);

using graph_t = vector <vector<int>>;

void dfs(
        const int start,
        const graph_t &graph,
        vector<bool> &used,
        int &count
) {

    used[start] = true;

    for (auto &&vert : graph[start]) {
        if (used[vert]) continue;
        count++;
        dfs(vert, graph, used, count);

    }

}

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector <vector<int>> astronaut) {

    graph_t graph(n);
    for (auto &&a : astronaut) {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }

    vector<bool> used(n, false);

    long result = 0;
    long sum = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        int size = 1;

        dfs(i, graph, used, size);

        // A*B + A*C + A*D + B*C + B*D + C*D = A*B + (A+B)*C + (A+B+C)*D
        result += sum * size;
        sum += size;
    }

    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector <string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector <vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

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
