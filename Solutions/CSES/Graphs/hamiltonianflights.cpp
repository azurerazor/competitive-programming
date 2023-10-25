#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> graph;

vector<vector<ll>> memo(20, vector<ll>((1 << 20), -1));

const ll MOD = 1e9 + 7;

ll dp(int node, int mask) {
    if (mask == 0) return (node == n-1);
    if (!(mask & (1 << (n-1)))) return 0;

    if (memo[node][mask] != -1) return memo[node][mask];

    ll ans = 0;

    for (auto v : graph[node]) {
        if (mask & (1 << v)) {
            ans += dp(v, mask ^ (1 << v));
            ans %= MOD;
        }
    }

    return memo[node][mask] = ans;
}

int main() {
    cin >> n >> m;
    graph = vector<vector<int>>(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    cout << dp(0, (1 << n) - 2);
}