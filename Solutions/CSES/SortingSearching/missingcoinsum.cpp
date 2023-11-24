#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n; cin >> n;
 
    vector<ll> coinzzzz(n);
    for (int i = 0; i < n; i++) cin >> coinzzzz[i];
 
    sort(coinzzzz.begin(), coinzzzz.end());
 
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        if (sm+1 < coinzzzz[i]) break;
        sm += coinzzzz[i];
    }
 
    cout << (sm+1) << '\n';
    return 0;
}