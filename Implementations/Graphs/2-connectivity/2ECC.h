/*
* Source: own
* Desc: Finds 2-edge connected components in a graph. Each vertex will be labeled by component ID in the cmp vector.
* Test: https://judge.yosupo.jp/problem/two_edge_connected_components
*/

#pragma once

struct BCCE {
    int n, t, num_cmp;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> low, tin, st, cmp;

    BCCE(vector<vector<int>>& g) {
        adj = vector<vector<int>>(g);
        n = g.size();
        vis = vector<bool>(n);
        low = tin = cmp = vector<int>(n);
        st.reserve(n);
        t = num_cmp = 0;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, i);
        }
    }

    void dfs(int u, int p) {
        vis[u] = 1;
        st.push_back(u);
        tin[u] = low[u] = t++;

        for (auto v : adj[u]) {
            // for multi-edges, add condition to check for duplicate parent edge
            if (v = p) continue;
            
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
        }

        if (low[u] == tin[u]) {
            while (st.back() != u) {
                cmp[st.back()] = num_cmp;
                st.pop_back();
            }
            cmp[u] = num_cmp++;
            st.pop_back();
        }
    }
};
