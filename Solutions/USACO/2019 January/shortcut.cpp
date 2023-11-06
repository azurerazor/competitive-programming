#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
pair<vector<T>, vector<int>> dijkstra(vector<vector<pair<int, T>>>& graph, int sp) {
    vector<T> d(graph.size(), -1);
    vector<int> par(graph.size(), sp);
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, sp});
    d[sp] = 0;
    vector<bool> vis(graph.size(), false);

    while (pq.size()) {
        int c = pq.top().second;
        int cd = pq.top().first;
        pq.pop();

        if (vis[c]) continue;
        vis[c] = true;

        for (auto [t, w] : graph[c]) {
            if (d[c] + w <= d[t] || d[t] == -1) {
                par[t] = ((d[c] + w == d[t]) ? min(par[t], c) : c);
                d[t] = d[c] + w;
                pq.push({d[t], t});
            }
        }
    }

    return {d, par};
}

int main() {
    ifstream fin("shortcut.in");
    ofstream fout("shortcut.out");

    int n, m, t;
    fin >> n >> m >> t;

    vector<ll> cows(n);
    for (int i = 0; i < n; i++) fin >> cows[i];

    vector<vector<pair<int, ll>>> g(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        fin >> a >> b >> w;
        a--; b--;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    auto [d, p] = dijkstra<ll>(g, 0);

    vector<ll> traversals(n, 0);
    for (int i = 0; i < n; i++) {
        traversals[i] += cows[i];
        int temp = i;
        while (p[temp] != temp) {
            traversals[p[temp]] += cows[i];
            temp = p[temp];
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, traversals[i]*(d[i]-t));
    }

    fout << ans << '\n';
    return 0;
}
