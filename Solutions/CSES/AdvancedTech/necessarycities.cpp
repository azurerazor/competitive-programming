#include <bits/stdc++.h>
using namespace std;

struct CutVertex {
    int n, t;
    vector<vector<int>> graph;
    vector<bool> vis;
    vector<int> order, lowlink, cuts;

    CutVertex(vector<vector<int>>& adj) {
        graph = vector<vector<int>>(adj);
        n = graph.size();
        t = 0;
        vis = vector<bool>(n);
        lowlink = order = vector<int>(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) root(i);
        }
    }

    void root(int u) {
        vis[u] = 1;
        int fwe = 0;
        order[u] = lowlink[u] = t++;

        for (auto v : graph[u]) {
            if (vis[v]) continue;
            fwe++;
            dfs(v, u);
        }

        if (fwe-1) cuts.push_back(u);
    }

    void dfs(int u, int p) {
        vis[u] = 1;
        order[u] = lowlink[u] = t++;
        bool is_cut = 0;

        for (auto v : graph[u]) {
            if (v == p) continue;

            if (vis[v]) {
                lowlink[u] = min(lowlink[u], order[v]);
            } else {
                dfs(v, u);
                lowlink[u] = min(lowlink[u], lowlink[v]);

                if (lowlink[v] >= order[u]) {
                    is_cut = 1;
                }
            }
        }

        if (is_cut) cuts.push_back(u);
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

    CutVertex v = CutVertex(graph);

    cout << v.cuts.size() << '\n';
    
    for (auto u : v.cuts) cout << u+1 << ' ';
    cout << '\n';
    return 0;
}