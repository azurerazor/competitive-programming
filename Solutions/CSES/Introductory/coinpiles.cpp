#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
 
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll diff = abs(a-b);
        if (a<b) swap(a,b);
        if (a-2*diff >= 0 && (a-2*diff)%3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}