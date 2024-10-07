#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll expo(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p&1) ans = (ans * b) % mod;
        b= (b * b) % mod;
        p >>= 1;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("poetry.in", "r+", stdin);
    freopen("poetry.out", "w+", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> dp(k+1);
    vector<pair<int, int>> words;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int w, r;
        cin >> w >> r;
        r--;
        words.emplace_back(w, r);
    }

    for (int i = 0; i < k; i++) {
        for (auto [w, r] : words) {
            if (i + w > k) continue;
            dp[i+w] += dp[i];
            dp[i+w] %= mod;
        }
    }

    vector<ll> rc(n);

    for (auto [w, r] : words) {
        rc[r] += dp[k - w];
        rc[r] %= mod;
    }

    vector<int> rs(26);

    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        rs[c - 'A']++;
    }

    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        if (!rs[i]) continue;
        ll cur = 0;
        for (int j = 0; j < n; j++) {
            cur += expo(rc[j], rs[i]);
            cur %= mod;
        }

        ans = (ans * cur) % mod;
    }

    cout << ans << '\n';
    return 0;
}