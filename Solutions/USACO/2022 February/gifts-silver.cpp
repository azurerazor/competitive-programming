#include <bits/stdc++.h>
using namespace std;

int bfs(int cow, vector<vector<int>>& ranks, vector<vector<int>>& graph) {
    int n = graph.size();
    queue<int> q;
    vector<bool> vis(n);
    int minRank = ranks[cow][cow];
    q.push(cow);
    vis[cow] = true;

    while (q.size()) {
        int c = q.front();
        q.pop();

        for (auto v : graph[c]) {
            if (!vis[v]) {
                minRank = min(minRank, ranks[cow][v]);
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return minRank;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int>> perms(n, vector<int>(n));
    vector<vector<int>> ranks(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> perms[i][j];
            perms[i][j]--;
            ranks[i][perms[i][j]] = j;
        }
    }

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ranks[i][i]; j++) {
            graph[perms[i][j]].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << perms[i][bfs(i, ranks, graph)]+1 << '\n';
    }

    return 0;
}
