#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n;
vector<tuple<int, int, int>> prj;
vector<ll> memo(200005, -1);
 
ll dp(int curr) {
    if (curr >= n) return 0;
    if (memo[curr] != -1) return memo[curr];
 
    auto [s, e, p] = prj[curr];
 
    int l = curr+1, r = n;
 
    while (l != r) {
        int m = l + (r-l)/2;
        if (get<0>(prj[m]) > e) r = m;
        else l = m+1;
    }
 
    ll res = max(dp(l) + p, dp(curr+1));
 
    return memo[curr] = res;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        prj.push_back({s,e,p});
    }
 
    sort(prj.begin(), prj.end());
 
    cout << dp(0) << '\n';
    return 0;
}
