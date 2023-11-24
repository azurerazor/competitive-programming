#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, t;
    cin >> n >> t;
 
    vector<ll> machines(n);
    for (int i = 0; i < n; i++) cin >> machines[i];
 
    ll l = 0; ll r = 1e18;
 
    while (l != r) {
        ll m = l+(r-l)/2;
 
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += m/machines[i];
            if (sum >= t) break;
        }
 
        if (sum >= t) {
            r = m;
        } else {
            l = m+1;
        }
    }
 
    cout << l << '\n';
    return 0;
}