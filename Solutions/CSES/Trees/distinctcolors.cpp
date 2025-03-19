#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

set<int> colorSet[MAXN];
vector<int> colors;

void stl(int n, int p, vector<vector<int>>& tree) {
    for (auto v : tree[n]) {
        if (v == p) continue;
        stl(v, n, tree);
        if (colorSet[v].size() > colorSet[n].size()) swap(colorSet[v], colorSet[n]);

        for (set<int>::iterator i = colorSet[v].begin(); i != colorSet[v].end(); i++) {
            colorSet[n].insert(*i);
        }
    }

    colors[n] = colorSet[n].size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        colorSet[i].insert(v);
    }

    vector<vector<int>> tree(n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    colors = vector<int>(n, 1);

    stl(0,0,tree);

    for (auto v : colors) cout << v << ' ';
    cout << endl;
    return 0;
}