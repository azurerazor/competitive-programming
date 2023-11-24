#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n, t;
    cin >> n >> t;
 
    vector<ll> psum(n+1);
    map<ll, ll> m;
    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        psum[i] = a + psum[i-1];
    }
 
    ll count = 0;
 
    for (int i = 0; i <= n; i++) {
        if (!m.count(psum[i])) {
            m[psum[i]] = 0;
        }
        if (m.count(psum[i] - t)) {
            count += m[psum[i] - t];
        }
        m[psum[i]]++;
    }
 
    cout << count << '\n';
    return 0;
}