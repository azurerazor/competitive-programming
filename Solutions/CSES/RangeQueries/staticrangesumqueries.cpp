#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    int n, q;
    cin >> n >> q;
 
    vector<ll> ps;
    ps.push_back(0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ps.push_back(ps[i]+a);
    }
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a-1] << '\n';
    }
 
    return 0;
}
