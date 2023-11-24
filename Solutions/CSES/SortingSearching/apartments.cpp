#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.rbegin(), x.rend()
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> ppl(n);
    vector<int> apts(m);
 
    for (int i = 0; i < n; i++) cin >> ppl[i];
    for (int i = 0; i < m; i++) cin >> apts[i];
    sort(all(ppl));
    sort(all(apts));
    int p1 = 0, p2 = 0;
    int ans = 0;
 
    while (p1 < n && p2 < m) {
        if (abs(ppl[p1] - apts[p2]) <= k) {
            ans++; p1++; p2++;
        } else if (ppl[p1] > apts[p2]) {
            p1++;
        } else p2++;
    }
 
    cout << ans << '\n';
    return 0;
}