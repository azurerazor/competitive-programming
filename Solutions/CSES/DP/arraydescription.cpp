#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
vector<vector<ll>> memo(200001, vector<ll>(101, -1));
vector<int> arr;
int n, m;
 
ll dp(int ind, int prev) {
    if (prev > m || prev < 1) return 0;
    if (ind >= n) return 1;
 
    if (memo[ind][prev] != -1) return memo[ind][prev];
 
    if (arr[ind] != 0) {
        return memo[ind][prev] = (abs(arr[ind] - prev) <= 1) ? dp(ind + 1, arr[ind]) % MOD : 0;
    } else {
        ll sum = 0;
        for (int i = -1; i <= 1; i++) {
            sum += dp(ind + 1, prev + i);
            sum %= MOD;
        }
 
        return memo[ind][prev] = sum;
    }
}
 
int main() {
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
 
    ll ans = 0;
 
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) {
            ans += dp(1, i);
            ans %= MOD;
        }
    } else {
        ans = dp(0, arr[0]);
    }
 
    cout << ans << endl;
}