#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll mod;
vector<ll> p;

// ll dp(int pr, int l) {
//     if (pr >= size(p)) return 1;
//     if (DP[pr][l] != -1) return DP[pr][l];

//     ll ans = dp(pr+1, l);
//     for (int i = p[pr]; i <= l; i *= p[pr]) {
//         ans += (ll) i * (dp(pr+1, l-i));
//         ans %= mod;
//     }

//     return DP[pr][l] = ans;
// }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("exercise.in", "r+", stdin);
    freopen("exercise.out", "w+", stdout);

    cin >> n >> mod;

    vector<bool> sieve(10001, 1);
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i*i <= 10000; i++) if (sieve[i]) {
        for (int j = i * i; j <= 10000; j += i) sieve[j] = 0;
    }

    for (int i = 2; i < 10000; i++) if (sieve[i]) p.push_back(i);

    vector<vector<ll>> dp(2, vector<ll>(n+1));
    dp[0][0] = dp[1][0] = 1;

    for (auto v : p) {
        for (int i = v; i <= n; i *= v) {
            for (int j = n; j - i >= 0; j--) {
                dp[1][j] += (dp[0][j-i] * (ll)i) % mod;
                dp[1][j] %= mod;
            }
        }
        swap(dp[0], dp[1]);
        dp.pop_back();
        dp.push_back(dp[0]);
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[1][i];
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}
