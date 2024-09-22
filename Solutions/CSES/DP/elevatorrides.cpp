#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1000000005;
 
pair<int, int> dp[(1 << 20)];
vector<int> w;
int n, x;
set<pair<int, int>> states;
 
signed main() {
    for (int i = 0; i < (1 << 20); i++) dp[i] = {INF, INF};
 
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> x;
 
    w = vector<int>(n);
 
    for (int i = 0; i < n; i++) cin >> w[i];
 
    dp[0] = {1, 0};
 
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                pair<int, int> cur = dp[i ^ (1 << j)];
 
                if (cur.second + w[j] > x) {
                    cur = {cur.first + 1, w[j]};
                } else {
                    cur.second += w[j];
                }
 
                dp[i] = min(dp[i], cur);
            }
        }
    }
 
    cout << dp[(1 << n) - 1].first << '\n';
 
    return 0;
}