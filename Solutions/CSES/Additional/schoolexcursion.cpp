#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> f(n+1);
    queue<int> q;
    bitset<200000> vis;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            q.push(i);
            vis[i] = 1;
            int cur = 0;

            while (q.size()) {
                int u = q.front();
                q.pop();
                cur++;
                for (auto v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            f[cur]++;
        }
    }

    vector<int> ws;

    for (int i = 0; i < n; i++) {
        if (f[i+1]) {
            f[i+1]--;
            ws.push_back(i+1);
        }
        if (2*(i+1) <= n) f[2*(i+1)] += f[i+1]/2;
        if (f[i+1] % 2) ws.push_back(i+1);
    }

    bitset<200001> vals;
    vals[0] = 1;
    for (auto w : ws) vals |= (vals << w);

    for (int i = 1; i <= n; i++) cout << vals[i];
    return 0;
}