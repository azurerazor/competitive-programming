#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
#define sz(x) int((x).size())
 
vvi mult(const vvi& a, const vvi& b) {
    int n = sz(a);
    vvi res(n, vi(n));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][k] += a[i][j] * b[j][k];
                res[i][k] %= MOD;
            }
        }
    }
 
    return res;
}
 
ll expo(ll p, vvi& adj) {
    int n = sz(adj);
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;
 
    while (p) {
        if (p&1) {
            res = mult(res, adj);
        }
        adj = mult(adj, adj);
        p >>= 1;
    }
 
    return res[0][n-1];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m; ll k;
    cin >> n >> m >> k;
 
    vvi adj(n, vi(n));
 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a][b] += 1;
    }
 
    cout << expo(k, adj) << '\n';
    return 0;
}