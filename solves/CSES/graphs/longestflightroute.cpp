#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> memo;
vector<int> parent;
const int ninf = -1e9;

int dp_or_dfs_idk(int node) {
    if (node == n - 1) return 1;
    if (memo[node] != -1) return memo[node];

    int maxD = ninf;

    for (auto v : graph[node]) {
        int curr = dp_or_dfs_idk(v) + 1;

        if (curr > maxD) {
            maxD = curr;
            parent[node] = v;
        }
    }

    return memo[node] = maxD;
}

int main() {
    cin >> n >> m;

    graph = vector<vector<int>> (n);
    memo = vector<int>(n, -1);
    parent = vector<int>(n, 0);

    parent[n - 1] = n - 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    int ans = dp_or_dfs_idk(0);

    if (ans > 0) {
        cout << ans << endl;
        int i = 0;
        cout << i + 1;

        while (i != parent[i]) {
            cout << " " << parent[i] + 1;
            i = parent[i];
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}