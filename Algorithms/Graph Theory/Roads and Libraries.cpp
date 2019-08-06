#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/torque-and-development/
 */

using namespace std;

vector <string> split_string(string);


void dfs(int v,
         const vector <vector<int>> &cities,
         vector<bool> &used,
         vector<int> &comp
) {
    used[v] = true;
    comp.push_back(v);
    for (auto &&to : cities[v]) {
        if (!used[to]) {
            dfs(to, cities, used, comp);
        }
    }


}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector <vector<int>> cities) {

    // if(c_road > c_lib){
    //     return n * c_lib;
    // }

    vector<bool> used(n + 1, false);


    vector <vector<int>> graph(n + 1);

    for (auto &&city : cities) {
        graph[city[0]].push_back(city[1]);
        graph[city[1]].push_back(city[0]);
    }


    long result = 0;
    for (int vtx = 1; vtx <= n; vtx++) {
        if (used[vtx]) {
            continue;
        }
        vector<int> comp;

        dfs(vtx, graph, used, comp);


        if (c_road > c_lib) {
            result += (comp.size()) * c_lib;
        } else {
            result += (comp.size() - 1) * c_road + c_lib;
        }

    }


    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector <string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector <vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
