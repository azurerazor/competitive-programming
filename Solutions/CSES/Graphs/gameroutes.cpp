#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<ll> memo;

int n, m;

ll dfs(int node) {
    if (node == n - 1) return 1;
    if (memo[node] != -1) return memo[node];

    ll ans = 0;
    for (auto v : graph[node]) {
        ans += dfs(v);
        ans %= MOD;
    }

    return memo[node] = ans;
}

int main() {
    cin >> n >> m;

    graph = vector<vector<int>> (n);
    memo = vector<ll>(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    cout << dfs(0) << endl;
}