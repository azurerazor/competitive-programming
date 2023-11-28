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
    int sz, lsz;
    bl(vvi& graph) {
        g = graph; sz = g.size(); lsz = __lg(sz)+1;
        depth = vi(sz);
        up = vvi(lsz, vi(sz, 0));
        dfs(0);
    }
    void dfs(int a) {
        for (auto v : g[a]) {
            if (v == up[0][a]) continue;
            up[0][v] = a;
            for (int j = 1; j < lsz; j++) {
                up[j][v] = up[j-1][up[j-1][v]];
            }

            depth[v] = depth[a] + 1;
            dfs(v);
        }
    }
    int jump(int v, int k) {
        int ans = v;
        for (int i = lsz-1; i >= 0; i--) {
            if (k & (1 << i)) {
                ans = up[i][ans];
            }
        }
        return ans;
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = jump(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int i = lsz-1; i >= 0; i--) {
            if (up[i][a] != up[i][b]) {
                a = up[i][a]; b = up[i][b];
            }
        }
        return up[0][a];
    }

    int dist(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }
};
