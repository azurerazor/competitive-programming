#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll fastExpo(ll b, ll p, ll m) {
    ll res = 1;
    while (p) {
        if (p&1) {
            res *= b;
            res %= m;
        }
        b *= b;
        b %= m;
        p >>= 1;
    }
    return res;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t; cin >> t;
 
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
 
        // totient of 1e9+7 is 1e9+6 because prime or whatever
        cout << fastExpo(a, fastExpo(b, c, 1e9+6), 1e9+7) << '\n';
    }
 
    return 0;
}