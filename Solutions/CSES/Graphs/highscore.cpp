#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e16;
typedef tuple<int, int, ll> edge;

ll bellmanFord(vector<edge>& ed, int sp, int n) {
    vector<ll> dist(n, -inf);
    vector<bool> reach(n, false);
    sort(ed.begin(), ed.end());
    dist[sp] = 0;
    reach[sp] = 1;

    for (int i = 0; i < n; i++) {
        for (auto [a,b,w] : ed) {
            if (dist[a] == inf) continue;
            if (dist[b] < dist[a] + w) {
                dist[b] = ((i < n-1) ? dist[a]+w : inf);
            }

            if (reach[a]) reach[b] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto [a,b,w] : ed) {
            if (dist[a] == inf && reach[a]) dist[b] = inf;
        }
    }

    return dist[n-1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> ed;

    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;
        ed.push_back({a,b,w});
    }

    ll ans = bellmanFord(ed, 0, n);

    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}