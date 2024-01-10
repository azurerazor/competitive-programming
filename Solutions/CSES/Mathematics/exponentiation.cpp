#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
 
ll fastExpo(ll b, ll p) {
    if (!p) return 1;
    ll temp = fastExpo(b, p/2);
    temp *= temp;
    temp %= MOD;
    if (p % 2) temp *= b;
    return temp % MOD;
}
 
int main() {
    int c;
    cin >> c;
 
    while (c--) {
        int a, b;
        cin >> a >> b;
 
        cout << fastExpo(a,b) << '\n';
    }
    return 0;
}
