#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef tuple<ll, int, int> edge;

struct DSU {
    vector<int> s;
    int groups;
    DSU(int n) {s = vector<int>(n, -1); groups = n;}
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

pair<bool, ll> kruskal(vector<edge> e, int n) {
    DSU d = DSU(n);
    ll cost = 0;
    int ed = 0;
    sort(e.begin(), e.end());
    for (auto [w,a,b] : e) {
        if (d.join(a,b)) {
            cost += w;
            ed++;
        }
    }

    return {(ed == n-1), cost};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> e;

    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;

        e.push_back({w,a,b});
    }

    auto [a,b] = kruskal(e, n);

    if (a) cout << b << '\n';
    else cout << "IMPOSSIBLE" << '\n';
}