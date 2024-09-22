#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    vector<int> dp;
 
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        int l = lower_bound(dp.begin(), dp.end(), v) - dp.begin();
        if (l == dp.size()) dp.push_back(v);
        else dp[l] = v;
    }
 
    cout << dp.size() << '\n';
    return 0;
}