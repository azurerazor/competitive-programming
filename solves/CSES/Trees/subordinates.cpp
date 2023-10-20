#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> children;

int dfs(int node) {
    int ans = 0;

    for (auto v : tree[node]) {
        ans += dfs(v) + 1;
    }

    return children[node] = ans;
}

int main() {
    int n;
    cin >> n;

    tree = vector<vector<int>>(n);

    for (int i = 1; i < n; i++) {
        int a; cin >> a; a--;

        tree[a].push_back(i);
    }

    children = vector<int>(n, 0);

    dfs(0);

    for (int i = 0; i < n; i++) cout << children[i] << " ";
    cout << endl;
    return 0;
}
