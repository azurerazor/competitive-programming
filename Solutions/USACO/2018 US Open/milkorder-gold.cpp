#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<pair<int, int>>>& g, int obv, vector<int>& ind) {
    vector<int> top;
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = ind.size();

    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) pq.push(i);
    }

    while (pq.size()) {
        int c = pq.top();
        pq.pop();
        top.push_back(c);

        for (auto [v, idx] : g[c]) {
            if (idx >= obv) continue;
            if (--ind[v] == 0) pq.push(v);
        }
    }

    return top;
}

int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    int n, m;
    fin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int c, p;
        fin >> c >> p;
        p--;

        for (int j = 1; j < c; j++) {
            int v;
            fin >> v;
            v--;
            graph[p].push_back({v, i});
            p = v;
        }
    }

    int l = 0, r = m;
    vector<int> top;

    while (l < r) {
        int mid = l + (r-l+1)/2;

        vector<int> ind(n);
        for (int i = 0; i < n; i++) {
            for (auto [v, obv] : graph[i]) {
                if (obv < mid) ind[v]++;
            }
        }

        top = topoSort(graph, mid, ind);
        if (top.size() == n) {
            l = mid;
        } else {
            r = mid-1;
        }
    }

    vector<int> ind(n);
    for (int i = 0; i < n; i++) {
        for (auto [v, obv] : graph[i]) {
            if (obv < l) ind[v]++;
        }
    }

    top = topoSort(graph, l, ind);

    for (int i = 0; i < n; i++) {
        if (i != 0) fout << ' ';
        fout << top[i]+1;
    }

    fout << '\n';
    return 0;
}