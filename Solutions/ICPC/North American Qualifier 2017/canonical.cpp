#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(coins[n-1] + coins[n-2] + 1, 1e9);
    vector<int> greed(coins[n-1] + coins[n-2] + 1, 1);
    dp[0] = 0;

    for (int c : coins) {
        for (int i = 0; i < dp.size() - c; i++) {
            if (dp[i] + 1 <= dp[i+c]) {
                dp[i+c] = dp[i] + 1;
                greed[i+c] = 1;
            } else {
                greed[i+c] = 0;
            }
        }
    }

    int ans = 1;
    for (auto c : greed) { ans = min(c, ans); }

    cout << (ans ? "canonical\n" : "non-canonical\n");
    return 0;
}