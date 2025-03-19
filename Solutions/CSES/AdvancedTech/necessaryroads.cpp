#include <bits/stdc++.h>
using namespace std;

struct Bridges {
    int n, t;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> lowlink, order;
    vector<pair<int, int>> bridges;

    Bridges(vector<vector<int>>& g) {
        adj = vector<vector<int>>(g);
        n = g.size();
        vis = vector<bool>(n);
        lowlink = order = vector<int>(n);
        t = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, i);
        }
    }

    void dfs(int u, int p) {
        vis[u] = 1;
        order[u] = lowlink[u] = t++;

        for (auto v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                lowlink[u] = min(lowlink[u], order[v]);
            } else {
                dfs(v, u);
                lowlink[u] = min(lowlink[u], lowlink[v]);
                
                if (lowlink[v] > order[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
};

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

    Bridges b = Bridges(graph);

    cout << b.bridges.size() << '\n';

    for (auto [a, b] : b.bridges) {
        cout << a+1 << ' ' << b+1 << '\n';
    }

    return 0;
}