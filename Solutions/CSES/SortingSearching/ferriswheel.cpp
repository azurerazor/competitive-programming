#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, w;
    cin >> n >> w;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
 
    int p1 = 0;
    int p2 = n-1;
 
    int ans = 0;
 
    while (p1 <= p2) {
        ans++;
        if (v[p1] + v[p2] <= w) {
            p1++;
        }
        p2--;
    }
 
    cout << ans << '\n';
    return 0;
}