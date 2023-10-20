#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up;
vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;
int LOG = 21;
int maxDepth;
int n;

void dfs(int a) {
    for (auto v : tree[a]) {
        if (v == parent[a]) continue;
        up[v][0] = a;
        for (int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

int main() {
    int q;
    cin >> n >> q;

    parent = vector<int>(n, 0);
    depth = vector<int>(n, 0);
    tree = vector<vector<int>>(n);

    for (int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        tree[a].push_back(i);
        tree[i].push_back(a);
        parent[i] = a;
        depth[i] = depth[a] + 1;
    }

    up = vector<vector<int>>(n, vector<int>(LOG, 0));

    dfs(0);

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;

        if (k > depth[x]) {
            cout << -1 << endl;
        } else {
            for (int j = LOG - 1; j >= 0; j--) {
                if (k & (1 << j)) {
                    x = up[x][j];
                }
            }

            cout << x + 1 << endl;
        }
    }
}