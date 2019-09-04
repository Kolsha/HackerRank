#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/count-luck/
 */

using namespace std;

vector <string> split_string(string);

using point = pair<int, int>;

bool checkBounds(const vector <string> &matrix, int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (y >= matrix.size() || x >= matrix.front().length()) {
        return false;
    }
    return true;
}

bool isRoad(const vector <string> &matrix, point p) {
    int x = p.first;
    int y = p.second;
    return checkBounds(matrix, x, y) && (matrix[y][x] == '.' || matrix[y][x] == '*');
}

std::pair<int, int> operator+(const std::pair<int, int> &x, const std::pair<int, int> &y) {
    return std::make_pair(x.first + y.first, x.second + y.second);
}

bool findPath(vector <string> matrix, point start, int &l) {

    static const point dirs[] = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1}
    };
    int x = start.first;
    int y = start.second;
    if (!checkBounds(matrix, x, y)) {
        return false;
    }

    if (matrix[y][x] == 'X') {
        return false;
    }

    if (matrix[y][x] == '*') {
        return true;
    }


    matrix[y][x] = 'X';
    // int tmp = l;
    int possible = 0;
    for (auto &&d : dirs) {
        if (isRoad(matrix, start + d)) {
            possible++;
        }
    }
    // cout << "possible = " << possible << endl;


    for (auto &&d : dirs) {
        int tmp = 0;
        if (findPath(matrix, start + d, tmp)) {
            l += tmp;
            if (possible > 1)
                l++;
            return true;
        }
    }


    return false;


}

// Complete the countLuck function below.
string countLuck(vector <string> matrix, int k) {

    point start = {0, 0};
    for (int y = 0; y < matrix.size(); y++) {
        string &line = matrix[y];
        for (int x = 0; x < line.length(); x++) {
            if (line[x] == 'M') {
                start = {x, y};
                break;
            }
        }
    }
    int l = 0;
    findPath(matrix, start, l);
    cout << l << endl;
    return (l == k) ? "Impressed" : "Oops!";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector <string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector <string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

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
