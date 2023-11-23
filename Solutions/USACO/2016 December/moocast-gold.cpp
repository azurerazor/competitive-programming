#include <bits/stdc++.h>
using namespace std;

bool bfs(int maxw, vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    queue<int> q;
    vector<bool> vis(n);
    int visc = 0;
    q.push(0);
    vis[0] = true;

    while (q.size()) {
        int c = q.front();
        q.pop();
        visc++;

        for (auto [v, w] : g[c]) {
            if (!vis[v] && w <= maxw) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    return (visc == n);
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n; fin >> n;

    vector<pair<int, int>> pts(n);

    for (int i = 0; i < n; i++) fin >> pts[i].first >> pts[i].second;

    vector<int> weights;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int dx = abs(pts[i].first - pts[j].first);
            int dy = abs(pts[i].second - pts[j].second);
            weights.push_back(dx*dx + dy*dy);
            graph[i].push_back({j, dx*dx + dy*dy});
            graph[j].push_back({i, dx*dx + dy*dy});
        }
    }

    sort(weights.begin(), weights.end());

    int l = 0, r = weights.size() - 1;

    while (l != r) {
        int m = l + (r-l)/2;

        if (bfs(weights[m], graph)) {
            r = m;
        } else {
            l = m+1;
        }
    }

    fout << weights[l] << '\n';
    return 0;
}
