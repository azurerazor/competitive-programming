#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> ind(n);
    vector<bool> cyc(n), vis(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ind[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (ind[i] == 0) q.push(i);

    while (q.size()) {
        int u = q.front();
        q.pop();
        cyc[u] = 1;
        for (auto v : graph[u]) {
            if (--ind[v] == 0) q.push(v);
        }
    }

    int ans = n;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bool f = 1;
            q.push(i);
            while (q.size()) {
                int u = q.front(); q.pop();
                f = min(f, (bool)cyc[u]);
                for (auto v : graph[u]) {
                    if (!vis[v]) {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }

            ans -= f;
        }
    }

    cout << ans << '\n';
    return 0;
}