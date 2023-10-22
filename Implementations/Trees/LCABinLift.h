/*
* Source: own
* Desc: Allows for traversal of trees and LCA finding in O(log(n)) with O(nlog(n)) preprocess
* Test: https://cses.fi/problemset/task/1688/
*/

#pragma once

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct bl {
    vvi up, g; vi depth;
    int sz;
    bl(vvi& graph) {
        g = graph; sz = g.size();
        depth = vi(sz);
        up = vvi(sz, vi(__lg(sz) + 1, 0));
        dfs(0);
    }
    void dfs(int a) {
        for (auto v : g[a]) {
            if (v == up[a][0]) continue;
            up[v][0] = a;
            for (int j = 1; j <= __lg(sz); j++) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }

            depth[v] = depth[a] + 1;
            dfs(v);
        }
    }
    int jump(int v, int k) {
        int ans = v;
        for (int i = __lg(sz); i >= 0; i--) {
            if (k & (1 << i)) {
                ans = up[ans][i];
            }
        }
        return ans;
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = jump(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int i = __lg(sz); i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i]; b = up[b][i];
            }
        }
        return up[a][0];
    }

    int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};
