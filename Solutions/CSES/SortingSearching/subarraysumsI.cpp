#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, t; cin >> n >> t;
    vector<int> ps(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ps[i] = ps[i-1] + a;
    }
 
    int ans = 0;
    int p1 = 0, p2 = 1;
 
    while (p2 <= n) {
        if ((ps[p2] - ps[p1]) == t) {
            ans++; p1++; p2++;
        } else if (ps[p2] - ps[p1] < t) p2++;
        else p1++;
    }
 
    cout << ans << '\n';
    return 0;
}