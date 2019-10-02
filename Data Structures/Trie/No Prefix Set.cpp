#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
/*
 * Difficulty Hard
 * Max Score 50
 * https://www.hackerrank.com/challenges/no-prefix-set/
 * help this: https://www.geeksforgeeks.org/trie-insert-and-search/
 */
using namespace std;

constexpr int ALPHA_SIZE = 'j' - 'a' + 1;

inline int c_to_i(char c) {
    return int(c) - int('a');
}

struct TrieNode_t {
    struct TrieNode_t *childs[ALPHA_SIZE];
    bool isEndOfWord;
};
using TrieNode = TrieNode_t;

TrieNode *getNode() {
    TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHA_SIZE; i++)
        pNode->childs[i] = nullptr;

    return pNode;
}

void insert(TrieNode *root, const string &key) {
    TrieNode *runner = root;

    for (int i = 0; i < key.length(); i++) {
        int index = c_to_i(key[i]);
        if (!runner->childs[index])
            runner->childs[index] = getNode();

        runner = runner->childs[index];
    }

    // mark last node as leaf
    runner->isEndOfWord = true;
}

bool search(TrieNode *root, const string &key) {
    TrieNode *runner = root;

    for (int i = 0; i < key.length(); i++) {
        int index = c_to_i(key[i]);
        if (!runner->childs[index]) {
            return false;
        }

        runner = runner->childs[index];
        if (runner->isEndOfWord) {
            return true;
        }
    }

    return (runner != nullptr); //&& runner->isEndOfWord
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    TrieNode *root = getNode();
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (search(root, s)) {
            cout << "BAD SET" << endl;
            cout << s << endl;
            return 0;
        }
        insert(root, s);
    }

    cout << "GOOD SET" << endl;
    return 0;
}
