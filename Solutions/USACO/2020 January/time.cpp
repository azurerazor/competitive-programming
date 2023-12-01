#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> costs;
vector<vector<int>> graph;
vector<vector<ll>> memo(1000, vector<ll>(1001, -1));
const ll inf = 1e12;

ll dp(int city, int left) {
    if (left == 0) return ((city == 0) ? 0 : -inf);
    if (memo[city][left] != -1) return memo[city][left];

    ll res = -inf;

    for (auto u : graph[city]) {
        res = max(res, dp(u, left-1) + costs[u]);
    }

    return memo[city][left] = res;
}

int main() {
    ifstream fin("time.in");
    ofstream fout("time.out");

    int n, m; ll c;
    fin >> n >> m >> c;

    costs = vector<ll>(n);
    graph = vector<vector<int>>(n);

    for (int i = 0; i < n; i++) fin >> costs[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    ll ans = 0;
    for (ll i = 0; i <= 1000LL; i++) {
        ans = max(ans, dp(0, (int)i) - c*i*i);
    }

    fout << ans << '\n';
    return 0;
}