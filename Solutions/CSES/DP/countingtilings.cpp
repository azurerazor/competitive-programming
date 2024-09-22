#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int n, m;
ll memo[1000][(1 << 10)];
vector<vector<int>> graph;

ll dp(int i, int mask) {
    if (i >= m) return (!mask);
    if (memo[i][mask] != -1) return memo[i][mask];

    ll ans = 0;

    for (auto v : graph[mask]) {
        ans += dp(i+1, v);
        ans %= mod;
    }

    return memo[i][mask] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));

    cin >> n >> m;

    graph = vector<vector<int>>((1 << n));

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool f = 1;

            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) && (j & (1 << k))) {
                    f = 0;
                } else if (!(i & (1 << k)) && !(j & (1 << k))) {
                    if (k == n-1 || (i & (1 << (++k))) || (j & (1 << (k)))) f = 0;
                }
            }

            if (f) graph[i].push_back(j);
        }
    }

    cout << dp(0, 0) << '\n';
    return 0;
}