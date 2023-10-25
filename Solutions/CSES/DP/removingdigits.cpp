#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
 
    for (int i = n; i >= 0; i--) {
        if (dp[i] == INT_MAX) continue;
 
        vector<int> digits;
 
        int temp = i;
        while (temp > 0) {
            int d = temp % 10;
            digits.push_back(d);
            temp /= 10;
        }
 
 
        for (int j = 0; j < digits.size(); j++) {
            if (i - digits[j] >= 0) {
                dp[i - digits[j]] = min(dp[i - digits[j]], dp[i] + 1);
            }
        }
    }
 
    cout << dp[0] << endl;
}