#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void part1() {
    char f[199], t[100];
    map<string, string> graph;
    while (scanf("%20[^)])%s\n", f, t) != EOF) {
        string from = f;
        string to = t;
        graph[to] = from;
    }

    int direct = 0;
    int indirect = 0;
    for (auto &it: graph) {
        auto str_it = it.first;
        int first = 0;
        while (graph.find(str_it) != graph.end()) {
            if (!first) {
                ++direct;
                first = 1;
            } else {
                ++indirect;
            }
            str_it = graph[str_it];
        }
    }
    cout << direct + indirect << endl;
}

int dfs(map<string, map<string, int>> &graph, map<string, bool> &visited, string from, string to) {
    visited[from] = true;
    if (from == to) return 0;
    int best = 1e9;
    for (auto &it: graph[from]) {
        if (!visited[it.first])
            best = min(best, dfs(graph, visited, it.first, to) + 1);
    }
    return best;
}

void part2() {
    char f[199], t[100];
    map<string, map<string, int>> graph;
    while (scanf("%20[^)])%s\n", f, t) != EOF) {
        string from = f;
        string to = t;
        if (graph.find(to) == graph.end()) {
            graph[to] = map<string, int>();
        }
        graph[to][from] = 1;
        if (graph.find(from) == graph.end()) {
            graph[from] = map<string, int>();
        }
        graph[from][to] = 1;
    }
    map<string, bool> visited;

    cout << dfs(graph, visited, "YOU", "SAN") - 2 << endl;
}

int main() {
//    part1();
    part2();
}