#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
 
ll fastPow(ll b, ll p, ll M = MOD) {
    ll res = 1;
    while(p) {
        if(p&1) {
            res *= b;
            if (M>0) res %= M;
        }
        b *= b;
        if (M>0) b %= M;
        p >>= 1;
    }
    return res;
}
 
vector<ll> factorial(MAXN);
vector<ll> factInv(MAXN);
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i-1]*i % MOD;
        factInv[i] = fastPow(factorial[i], MOD-2);
    }
 
    string s;
    cin >> s;
 
    vector<int> freq(26);
 
    for (int i = 0; i < sz(s); i++) freq[(int) (s[i] - 'a')]++;
 
    ll ans = factorial[sz(s)];
 
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            ans *= factInv[freq[i]];
            ans %= MOD;
        }
    }
 
    cout << ans << '\n';
    return 0;
}