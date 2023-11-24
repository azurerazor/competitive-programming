#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> XOR(n+1,0);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        XOR[i] = (v^(XOR[i-1]));
    }
 
    while (q--) {
        int l, r; cin >> l >> r;
 
        cout << (XOR[r]^XOR[l-1]) << '\n';
    }
 
    return 0;
}