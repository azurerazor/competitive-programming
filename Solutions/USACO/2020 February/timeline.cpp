#include <bits/stdc++.h>
using namespace std;

void TopoSort(vector<vector<pair<int, int>>>& g, vector<int>& ind, vector<int>& res) {
    int n = ind.size();
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!ind[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        int c = q.front();
        q.pop();

        for (auto [v,w] : g[c]) {
            res[v] = max(res[v], res[c] + w);
            if (--ind[v] == 0) q.push(v);
        }
    }
}

int main() {
    ifstream fin("timeline.in");
    ofstream fout("timeline.out");

    int n, m, c;
    fin >> n >> m >> c;

    vector<int> early(n);

    for (int i = 0; i < n; i++) fin >> early[i];

    vector<int> ind(n, 0);
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < c; i++) {
        int a, b, d;
        fin >> a >> b >> d;
        a--; b--;
        graph[a].push_back({b,d});
        ind[b]++;
    }

    TopoSort(graph, ind, early);

    for (int i = 0; i < n; i++) fout << early[i] << '\n';
    return 0;
}
