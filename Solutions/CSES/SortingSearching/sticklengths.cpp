#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll cost(int v, vector<ll>& sticks) {
    ll cost = 0;
    for (auto s : sticks) cost += abs(s-v);
    return cost;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<ll> sticks(n);
    for (int i = 0; i < n; i++) cin >> sticks[i];
 
    int l = 1; int r = 1e9;
 
    while (l<r) {
        int m = l + (r-l)/2;
        if (cost(m, sticks) < cost(m+1, sticks)) {
            r = m;
        } else {
            l = m+1;
        }
    }
 
    cout << cost(l,sticks) << '\n';
}