#include <bits/stdc++.h>
using namespace std;

int dfs(int c, int p, int r, vector<vector<pair<int, int>>>& tree) {
    int ans = 1;

    for (auto [v, w] : tree[c]) {
        if (v == p) continue;
        if (w >= r) ans += dfs(v, c, r, tree);
    }

    return ans;
}

int main() {
    ifstream fin ("mootube.in");
    ofstream fout ("mootube.out");

    int n, q;
    fin >> n >> q;

    vector<vector<pair<int, int>>> tree(n);

    for (int i = 0; i < n-1; i++) {
        int u, v, r;
        fin >> u >> v >> r;
        u--; v--;
        tree[u].push_back({v, r});
        tree[v].push_back({u, r});
    }

    for (int i = 0; i < q; i++) {
        int v, r;
        fin >> r >> v;
        v--;
        fout << dfs(v, v, r, tree)-1 << '\n';
    }

    return 0;
}