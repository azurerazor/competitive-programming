#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef tuple<ll,int,int> edge;

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

ll kruskal(vector<edge> ed, int n) {
    DSU d;
    d.init(n);
    sort(ed.begin(), ed.end());
    reverse(ed.begin(), ed.end());

    ll cost = 0;
    for (auto [w,a,b] : ed) {
        if (d.join(a,b)) cost += w;
    }

    return cost;
}

int main() {
    ifstream fin("superbull.in");
    ofstream fout("superbull.out");

    int n;
    fin >> n;

    vector<ll> ids(n);

    for (int i = 0; i < n; i++) {
        fin >> ids[i];
    }

    vector<edge> ed;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ed.push_back({(ids[i]^ids[j]), i, j});
        }
    }

    sort(ed.begin(), ed.end());

    fout << kruskal(ed, n) << '\n';
    return 0;
}
