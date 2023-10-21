#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int len; int node;

void dfs(int n, int p, int d) {
    for (auto v : graph[n]) {
        if (v != p) {
            if (d + 1 > len) {
                len = d + 1;
                node = v;
            }
            dfs(v, n, d + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    graph = vector<vector<int>>(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // furthest node from 0
    dfs(0, -1, 0);
    len = 0;

    // longest path
    dfs(node, -1, 0);
    cout << len << endl;
}