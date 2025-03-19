#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
vector<ll> fac(2000001), inv(2000001);

ll binExp(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p&1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans;
}

ll DP[1002];
vector<pair<int, int>> pts;

ll choose(int n, int k) {
    ll top = fac[n];
    ll bottom = (inv[k] * inv[n-k]) % mod;
    return (top*bottom)%mod;
}

ll dp(int c) {
    if (c == (int)size(pts)-1) return mod-1;
    if (DP[c] != -1) return DP[c];

    ll ans = 0;
    auto [x, y] = pts[c];

    for (int i = c+1; i < pts.size(); i++) {
        auto [x2, y2] = pts[i];
        if (x2 < x || y2 < y) continue;
        ll cur = (choose(x2 + y2 - x - y, x2 - x) * (mod - dp(i))) % mod;
        ans += cur;
        ans %= mod;
    }

    return DP[c] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, -1, sizeof(DP));

    fac[0] = inv[0] = 1;

    for (int i = 1; i <= 2000000; i++) {
        fac[i] = (fac[i-1] * (ll)i) % mod;
    }

    inv[2000000] = binExp(fac[2000000], mod-2);
    for (int i = 2000000; i > 0; i--) {
        inv[i-1] = (inv[i] * (ll)i) % mod;
    }
    
    int n, m;
    cin >> n >> m;

    pts.emplace_back(1, 1);
    pts.emplace_back(n, n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
    }

    sort(begin(pts), end(pts));
    pts.erase(unique(begin(pts), end(pts)), end(pts));

    cout << dp(0) << '\n';
    return 0;
}