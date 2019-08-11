#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
/*
 * Difficulty Hard
 * Max Score 45
 * https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/
 * help this:
 * http://brestprog.by/topics/dijkstra/
 */
using namespace std;

class Graph {
private:
    vector <vector<int>> _graph;
    int _n;
public:
    Graph(int n) {
        _n = n;

        _graph.resize(_n);
    }

    void add_edge(int u, int v) {
        _graph[u].push_back(v);
        _graph[v].push_back(u);
    }

    vector<int> shortest_reach(int start) {
        vector<int> res(_n, INT_MAX);

        priority_queue <
        pair < int, int >,
                vector < pair < int, int >>,
                greater < pair < int, int >>
                                      > q;

        q.push({0, start});
        res[start] = 0;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            int dst = p.first, u = p.second;

            if (res[u] < dst) {
                continue;
            }

            for (auto &&v : _graph[u]) {
                int n_dst = dst + 6;
                if (n_dst < res[v]) {
                    res[v] = n_dst;
                    q.push({n_dst, v});
                }
            }


        }
        for (int i = 0; i < _n; i++) {
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }

        return res;
    }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

