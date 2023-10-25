#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    sort(coins.begin(), coins.end());

    for (auto j : coins) {
        for (int i = 0; i <= x; i++) {
            if (i + j <= x) {
                dp[i+j] += dp[i];
                dp[i+j] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}