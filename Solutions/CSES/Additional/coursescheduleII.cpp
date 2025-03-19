#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>>& g, vector<int> ind) {
    priority_queue<int> pq;
    vector<bool> vis(ind.size(), false);
    vector<int> seq;
    seq.reserve(ind.size());

    for (int i = 0; i < ind.size(); i++) {
        if (!ind[i]) {
            pq.push(i);
            vis[i] = true;
        }
    }

    while (pq.size()) {
        int c = pq.top();
        pq.pop();
        seq.push_back(c+1);

        for (auto v : g[c]) {
            if (!(--ind[v])) {
                pq.push(v);
                vis[v] = true;
            }
        }
    }

    return seq;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<int> indeg(n, 0);
    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[b].push_back(a);
        indeg[a]++;
    }

    auto seq = topoSort(graph, indeg);
    reverse(seq.begin(), seq.end());

    for (auto v : seq) cout << v << ' ';
    cout << '\n';
    return 0;
}