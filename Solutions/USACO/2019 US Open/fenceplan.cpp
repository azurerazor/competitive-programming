#include <bits/stdc++.h>
using namespace std;

int bfs(int sp, vector<vector<int>>& g, vector<bool>& vis, vector<pair<int, int>>& pts) {
    queue<int> q;
    int x1 = 2e9, y1 = 2e9, x2 = 0, y2 = 0;
    q.push(sp);
    vis[sp] = true;

    while (q.size()) {
        int c = q.front();
        q.pop();

        x1 = min(x1, pts[c].first);
        y1 = min(y1, pts[c].second);
        x2 = max(x2, pts[c].first);
        y2 = max(y2, pts[c].second);

        for (auto v : g[c]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return 2*(x2-x1) + 2*(y2-y1);
}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int n, m;
    fin >> n >> m;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) fin >> cows[i].first >> cows[i].second;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> vis(n, false);

    int minp = 2e9;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            minp = min(minp, bfs(i, graph, vis, cows));
        }
    }

    fout << minp << '\n';

    return 0;
}
