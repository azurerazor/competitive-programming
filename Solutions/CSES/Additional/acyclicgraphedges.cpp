#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;
vector<int> depth;

void dfs(int u, int p, vector<vector<int>>& graph) {
    depth[u] = depth[p] + 1;

    for (auto v : graph[u]) {
        if (v == p) continue;

        if (depth[v] != -1 && depth[u] < depth[v]) {
            ans.push_back({u, v});
        } else if (depth[v] == -1) {
            ans.push_back({u, v});
            dfs(v,u,graph);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth = vector<int>(n, -1);
    

    for (int i = 0; i < n; i++) {
        if (depth[i] == -1) {
            depth[i] = 0;
            dfs(i,i,graph);
        }
    }

    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
    return 0;
}