#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> tree;
vector<vector<int>> up;
vector<int> depths;
const int LOG = 21;

void dfs(int a) {
    for (auto v : tree[a]) {
        up[v][0] = a;
        for (int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        depths[v] = depths[a] + 1;
        dfs(v);
    }
}

int lca(int a, int b) {
    if (depths[a] < depths[b]) swap(a, b);

    int k = depths[a] - depths[b];

    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }

    if (a == b) return a + 1;

    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0] + 1;
}

int main() {
    cin >> n >> q;

    depths = vector<int>(n, 0);
    tree = vector<vector<int>>(n);
    up = vector<vector<int>>(n, vector<int>(LOG));

    for (int i = 1; i < n; i++) {
        int a; cin >> a; a--;

        tree[a].push_back(i);
    }

    dfs(0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        cout << lca(a, b) << endl;
    }
}