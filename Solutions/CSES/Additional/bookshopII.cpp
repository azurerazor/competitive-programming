#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vector<int> w, v;
    vector<array<int, 3>> data(n);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) cin >> data[j][i];
    }

    for (int i = 0; i < n; i++) {
        int c = data[i][0], p = data[i][1], m = data[i][2];

        for (int i = 1; i < m; i <<= 1) {
            w.push_back(c*i);
            v.push_back(p*i);
            m -= i;
        }
        if (m) {
            w.push_back(c*m);
            v.push_back(p*m);
        }
    }

    int m = w.size();

    // for (int i = 0; i < m; i++) cout << w[i] << ' ' << v[i] << '\n';

    vector<vector<int>> dp(2, vector<int>(x+1));
    int ans = 0;
    vector<int> emp(x+1);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= x; j++) {
            dp[1][j] = dp[0][j];
            if (j - w[i] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j-w[i]] + v[i]);
            }
            ans = max(ans, dp[1][j]);
        }
        swap(dp[0], dp[1]);
        dp.pop_back();
        dp.push_back(emp);
    }

    cout << ans << '\n';
    return 0;
}