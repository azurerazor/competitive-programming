#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> depths;
vector<int> parent;
int n;

void dfs(int u, int p) {
    for(auto v : tree[u]) {
        if (v != p) {
            depths[v] = depths[u] + 1;
            parent[v] = u;
            dfs(v, u);
        }
    }
}

bool lca(int a, int b) {
    int l = a;
    int r = b;
    if (depths[l] < depths[r]) swap(l, r);

    int steps = 0;

    while (depths[l] > depths[r]) {
        l = parent[l];
        steps++;
    }

    int j = steps;

    for (int i = 0; i <= 3 - j; i += 2) {
        if (l == r) {
            break;
        }

        l = parent[l];
        r = parent[r];
        steps += 2;
    }

    return (steps <= 3);
}

void solve() {
    int n;
    cin >> n;

    tree = vector<vector<int>>(n);
    depths = vector<int>(n);
    parent = vector<int>(n);
    depths[0] = 0;
    parent[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, 0);

    vector<int> perm(n);

    for (int i = 0; i < n; i++) {
        cin >> perm[i];
        perm[i]--;
    }

    bool f = true;

    for (int i = 1; i < n; i++) {
        f = lca(perm[i], perm[i - 1]);

        if (!f) {
            break;
        }
    }

    cout << f << endl;
}

int main() {
    int c;
    cin >> c;

    while (c--) solve();

    return 0;
}