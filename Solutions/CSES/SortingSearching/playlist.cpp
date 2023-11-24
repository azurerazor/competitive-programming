#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    map<int, int> m;
 
    int sp = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
 
        if (m.count(v)) {
            sp = max(sp, m[v]+1);
        }
        m[v] = i;
        ans = max(ans, i-sp+1);
    }
 
    cout << ans << '\n';
    return 0;
}