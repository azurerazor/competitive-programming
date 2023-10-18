#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
int v, e;

vector<ll> dijkstra(vector<vector<pair<int, ll>>>& edges, int sp) {
    vector<ll> d(v, inf);
    d[sp] = 0;
    vector<bool> vis(v, false);
    vis[sp] = true;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, sp});

    while (pq.size()) {
        int c = pq.top().second;
        ll cd = pq.top().first;
        pq.pop();

        if (cd != d[c]) continue;

        for (auto v : edges[c]) {
            if (cd + v.second < d[v.first]) {
                d[v.first] = cd + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }

    return d;
}

int main() {
    cin >> v >> e;

    vector<vector<pair<int, ll>>> edges(v);

    for (int i = 0; i < e; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;

        edges[a].push_back({b, w});
    }

    vector<ll> d = dijkstra(edges, 0);

    for (int i = 0; i < v; i++) {
        cout << d[i] << " ";
    }

    cout << endl;
}