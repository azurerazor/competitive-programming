/*
* Source: own
* Desc: Finds bridges in a graph. If looking for 2-edge CCs, check that file.
* Test: https://cses.fi/problemset/task/2076
*/

#pragma once

struct Bridges {
    int n, t;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> low, tin;
    vector<pair<int, int>> bridges;

    Bridges(vector<vector<int>>& g) {
        adj = vector<vector<int>>(g);
        n = g.size();
        vis = vector<bool>(n);
        low = tin = vector<int>(n);
        t = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, i);
        }
    }

    void dfs(int u, int p) {
        vis[u] = 1;
        tin[u] = low[u] = t++;

        for (auto v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
};
