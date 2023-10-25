#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
struct bl {
    vvi g, up;
    vi depth;
    int sz;
    bl (vvi& graph) {
        g = graph;
        sz = g.size();
        depth = vi(sz);
        up = vvi(sz, vi(__lg(sz) + 1));
        dfs(0);
    }
    void dfs(int a) {
        for (auto v : g[a]) {
            if (v == up[a][0]) continue;
            up[v][0] = a;
            depth[v] = depth[a] + 1;
 
            for (int i = 1; i <= __lg(sz); i++) {
                up[v][i] = up[up[v][i-1]][i-1];
            }
            dfs(v);
        }
    }
    int jump(int v, int k) {
        for (int i = __lg(sz); i >= 0; i--) {
            if (k & (1 << i)) {
                v = up[v][i];
            }
        }
        return v;
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = jump(a, depth[a] - depth[b]);
        if (a == b) return a;
 
        for (int i = __lg(sz); i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    }
    int dist(int a, int b) { return depth[a] + depth[b] - 2*depth[lca(a, b)];}
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    vvi tree(n);
 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
 
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    bl b = bl(tree);
 
    for (int i = 0; i < q; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
 
        cout << b.dist(c,d) << endl;
    }
}