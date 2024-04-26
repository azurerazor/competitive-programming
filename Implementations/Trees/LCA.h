/*
* Source: own
* Desc: Kth ancestor and LCA finding in O(log(n)) with O(nlog(n)) preprocess
* Test: https://judge.yosupo.jp/submission/204315
*/

#pragma once

struct BL {
    vector<vi> jmp, gr;
    vi dep;
    int S;
    BL(vector<vi>& g) {
        gr = g;
        S = __lg(sz(g));
        dep = vector<int>(sz(g));
        jmp = vector<vi>(S+1, vi(sz(g)));
        dfs(0);
    }
    void dfs(int u) {
        for (auto v : gr[u]) {
            if (v == jmp[0][u]) continue;
            jmp[0][v] = u;
            dep[v] = dep[u] + 1;
            for (int i = 1; i <= S; i++) {
                jmp[i][v] = jmp[i-1][jmp[i-1][v]];
            }

            dfs(v);
        }
    }
    int jump(int u, int k) {
        for (int i = S; i >= 0; i--) {
            if (k & (1 << i)) u = jmp[i][u];
        }
        return u;
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = jump(u, dep[u]-dep[v]);
        if (u == v) return u;
        
        for (int i = S; i >= 0; i--) {
            if (jmp[i][u] != jmp[i][v]) {
                u = jmp[i][u];
                v = jmp[i][v];
            }
        }

        return jmp[0][u];
    }

    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u,v)]; }
};
