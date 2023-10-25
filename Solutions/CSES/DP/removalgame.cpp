#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<ll> nums;
vector<vector<ll>> memo(5001, vector<ll>(5001, -1));
int n;
 
ll dp (int l, int r) {
    if (memo[l][r] != -1) return memo[l][r];
    
    if ((l + r) % 2 != n % 2) {
        if (l == r) return nums[l];
 
        return memo[l][r] = max(dp(l + 1, r) + nums[l], dp(l, r - 1) + nums[r]);
    } else {
        if (l == r) return 0;
 
        return memo[l][r] = min(dp(l + 1, r), dp(l, r - 1));
    }
}
 
int main() {
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
 
    cout << dp(0, n-1) << endl;
}