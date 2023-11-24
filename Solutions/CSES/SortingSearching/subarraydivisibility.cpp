#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n;
    cin >> n;
 
    vector<ll> ps(n+1);
    vector<ll> freq(n);
 
    for (int i = 1; i <= n; i++) {
        ll v; cin >> v;
        ps[i] = ps[i-1] + v;
    }
 
    for (int i = 0; i <= n; i++) {
        freq[((ps[i] % n) + n) % n]++;
    }
 
    ll ans = 0;
 
    for (int i = 0; i < n; i++) {
        ans += freq[i]*(freq[i]-1)/2;
    }
    
    cout << ans << '\n';
    return 0;
}