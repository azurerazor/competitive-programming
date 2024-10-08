#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+5;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int n = (int)size(graph);
    for (int i = 0; i < n; i++) if (d[i] < inf) pq.emplace(d[i], i);

    while (pq.size()) {
        auto [ud, u] = pq.top();
        pq.pop();
        if (d[u] < ud) continue;

        for (auto [v, w] : graph[u]) {
            if (d[v] > ud + w) {
                d[v] = ud + w;
                pq.emplace(d[v], v);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("dining.in", "r+", stdin);
    freopen("dining.out", "w+", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> dn(n, inf);
    dn[n-1] = 0;
    dijkstra(graph, dn);

    vector<int> dh(n, inf);

    for (int i = 0; i < k; i++) {
        int u, w;
        cin >> u >> w;
        dh[u-1] = dn[u-1] - w;
    }

    dijkstra(graph, dh);

    for (int i = 0; i < n-1; i++) {
        cout << (dh[i] <= dn[i]) << '\n';
    }

    return 0;
}