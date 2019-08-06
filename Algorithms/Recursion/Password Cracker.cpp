#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 40
 * https://www.hackerrank.com/challenges/password-cracker/
 */

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector <string> split(const string &);

/*
 * Complete the 'passwordCracker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY passwords
 *  2. STRING loginAttempt
 */
unordered_map<string, bool> cache;

void rec(
        const string &loginAttempt,
        const unordered_map<string, bool> &ps,
        const int max_len,
        const int min_len,
        int &curPos,
        string &way,
        string cache_key = ""
) {


    for (int i = min_len; i <= max_len; i++) {

        if (curPos + i > loginAttempt.length()) {
            return;
        }
        string key = loginAttempt.substr(curPos, i);
        if (ps.find(key) == ps.end()) {
            continue;
        }


        way += key + " ";
        cache_key += key;

        int temp_pos = curPos + i;


        if (cache.find(cache_key) == cache.end()) {
            cache.insert({cache_key, true});
            rec(loginAttempt,
                ps,
                max_len,
                min_len,
                temp_pos,
                way,
                cache_key
            );

            if (temp_pos == loginAttempt.length()) {
                curPos = temp_pos;

                return;
            }
        }
        const int len = key.length() + 1;
        way.erase(way.length() - len, len);

        cache_key.erase(cache_key.length() - key.length(), key.length());


    }

}

string passwordCracker(vector <string> passwords, string loginAttempt) {
    unordered_map<string, bool> ps;
    int max_len = 0, min_len = INT_MAX;
    for (auto &&p : passwords) {
        ps.insert({p, true});
        if (p.length() > max_len) {
            max_len = p.length();
        }
        if (p.length() < min_len) {
            min_len = p.length();
        }
    }

    int curPos = 0;

    cache.clear();

    string way;
    way.reserve(loginAttempt.length());
    rec(loginAttempt,
        ps,
        max_len,
        min_len,
        curPos,
        way);
    if (curPos < loginAttempt.length()) {
        return "WRONG PASSWORD";
    }

    return way.substr(0, way.length() - 1);


}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string passwords_temp_temp;
        getline(cin, passwords_temp_temp);

        vector <string> passwords_temp = split(rtrim(passwords_temp_temp));

        vector <string> passwords(n);

        for (int i = 0; i < n; i++) {
            string passwords_item = passwords_temp[i];

            passwords[i] = passwords_item;
        }

        string loginAttempt;
        getline(cin, loginAttempt);

        string result = passwordCracker(passwords, loginAttempt);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector <string> split(const string &str) {
    vector <string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
