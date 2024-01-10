#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
 
vvi mult(const vvi& a, const vvi& b) {
    int n = a.size();
    vvi res(n, vi(n, 2e18));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 2e18) continue;
            for (int k = 0; k < n; k++) {
                if (b[j][k] == 2e18) continue;
                res[i][k] = min(res[i][k], a[i][j] + b[j][k]);
            }
        }
    }
 
    return res;
}
 
ll expo(int k, vvi& adj) {
    int n = adj.size();
    vvi res(n, vi(n, 2e18));
    for (int i = 0; i < n; i++) res[i][i] = 0;
 
    while(k) {
        if (k&1) res = mult(res, adj);
        adj = mult(adj, adj);
        k >>= 1;
    }
 
    return res[0][n-1];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vvi adj(n, vi(n, 2e18));
 
    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        a--; b--;
 
        adj[a][b] = min(adj[a][b], w);
    }
 
    ll ans = expo(k, adj);
 
    cout << ((ans == 2e18) ? -1 : ans) << '\n';
    return 0;
}