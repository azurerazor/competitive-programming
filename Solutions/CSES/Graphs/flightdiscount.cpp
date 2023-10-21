#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e16;

int n, m;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& graph, int sp) {
    vector<ll> d(n, inf);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    d[sp] = 0;

    pq.push({0, sp});

    while (pq.size()) {
        ll c = pq.top().second;
        ll cd = pq.top().first;
        pq.pop();

        if (cd != d[c]) continue;

        for (auto v : graph[c]) {
            if (d[v.first] > d[c] + v.second) {
                d[v.first] = d[c] + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }

    return d;
}

int main() {
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n);
    vector<vector<pair<ll, ll>>> graphb(n);

    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a].push_back({b, w});
        graphb[b].push_back({a, w});
    }

    vector<ll> starts = dijkstra(graph, 0);
    vector<ll> ends = dijkstra(graphb, n - 1);

    ll minD = inf;

    for (int i = 0; i < n; i++) {
        for (auto v : graph[i]) {
            minD = min(minD, starts[i] + v.second / 2 + ends[v.first]);
        }
    }

    cout << minD << endl;
}