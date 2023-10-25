#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 1000000007;
vector<vector<ll>> memo(501, vector<ll>(62626, -1));
int c, sum;
 
ll dp(int curr, int left) {
    if (left < 0) return 0;
    if (curr >= c) return (left == 0);
 
    if (memo[curr][left] != -1) return memo[curr][left];
 
    ll sum = 0;
    sum += dp(curr + 1, left - curr);
    sum += dp(curr + 1, left);
    sum %= MOD;
 
    return memo[curr][left] = sum;
}
 
int main() {
    cin >> c;
 
    sum = c * (c + 1) / 2;
 
    if (sum % 2 != 0) {
        cout << 0 << endl;
    } else {
        cout << dp(1, sum / 2) % MOD << endl;
    }
    
    return 0;
}