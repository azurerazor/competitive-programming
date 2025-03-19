#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using P = pair<ll, int>;
const ll MOD = 1e9+7;

vector<ll> memo;

ll dp_count(int u, vector<vector<int>>& graph) {
    if (u == memo.size()-1) return 1;
    if (memo[u] != -1) return memo[u];

    ll ans = 0;

    for (auto v : graph[u]) {
        ans += dp_count(v, graph);
        ans %= MOD;
    }

    return memo[u] = ans;
}

ll dp_min(int u, vector<vector<int>>& graph) {
    if (u == memo.size()-1) return 0;
    if (memo[u] != -1) return memo[u];

    ll ans = 1e18;

    for (auto v : graph[u]) {
        ans = min(ans, dp_min(v, graph) + 1);
    }

    return memo[u] = ans;
}

ll dp_max(int u, vector<vector<int>>& graph) {
    if (u == memo.size()-1) return 0;
    if (memo[u] != -1) return memo[u];

    ll ans = -1e18;

    for (auto v : graph[u]) {
        ans = max(ans, dp_max(v, graph) + 1);
    }

    return memo[u] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a].push_back({b, w});
    }

    
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(n, 1e16);
    vector<vector<int>> par(n);
    dist[0] = 0;
    pq.emplace(0, 0);

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (d + w <= dist[v]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                    par[v] = vector<int>(0);
                }
                par[v].push_back(u);
            }
        }
    }

    cout << dist[n-1] << ' ';

    vector<vector<int>> shortgraph(n);

    for (int i = 0; i < n; i++) {
        for (auto p : par[i]) {
            shortgraph[p].push_back(i);
        }
    }

    memo = vector<ll>(n, -1);
    cout << dp_count(0, shortgraph) << ' ';

    memo = vector<ll>(n, -1);
    cout << dp_min(0, shortgraph) << ' ';

    memo = vector<ll>(n, -1);
    cout << dp_max(0, shortgraph) << '\n';

    return 0;
}