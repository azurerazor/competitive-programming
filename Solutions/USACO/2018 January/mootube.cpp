#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> s;
    int groups;
    void init(int n) {s = vector<int>(n, -1); groups = n;};
    int find(int v) { return ((s[v] < 0) ? v : s[v] = find(s[v]));}
    int size(int v) { return -s[find(v)]; }
    
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b]; s[b] = a;
        groups--;
        return true;
    }
};

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < n-1; i++) {
        int a, b, w;
        fin >> a >> b >> w;
        a--; b--;

        edges.push_back({w, a, b});
    }

    edges.push_back({0, 0, 0});

    sort(edges.begin(), edges.end());

    vector<tuple<int, int, int>> queries;

    for (int i = 0; i < q; i++) {
        int k, v;
        fin >> k >> v;
        v--;

        queries.push_back({k, v, i});
    }

    vector<int> res(q, 0);

    int p = q-1;
    DSU d;
    d.init(n);

    sort(queries.begin(), queries.end());

    for (int i = n-1; i >= 0; i--) {
        while(p >= 0 && get<0>(queries[p]) > get<0>(edges[i])) {
            res[get<2>(queries[p])] = d.size(get<1>(queries[p])) - 1;
            p--;
        }

        d.join(get<1>(edges[i]), get<2>(edges[i]));
    }

    for (int i = 0; i < q; i++) {
        fout << res[i] << endl;
    }
}