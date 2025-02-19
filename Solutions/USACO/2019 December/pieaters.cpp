#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> cows(300, vector<ll>(300));
vector pc(300, vector(300, vector<ll>(300)));

ll DP[300][300];

ll dp(int l, int r) {
    if (r < l) return 0;
    if (DP[l][r] != -1) return DP[l][r];

    ll ans = 0;
    for (int i = l; i <= r; i++) {
        ans = max(ans, dp(l, i-1) + dp(i+1, r) + pc[l][r][i]);
    }

    return DP[l][r] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, -1, sizeof(DP));

    freopen("pieaters.in", "r+", stdin);
    freopen("pieaters.out", "w+", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll w; int l, r;
        cin >> w >> l >> r;
        l--; r--;
        cows[l][r] = w;
    }

    for (int d = 0; d < 300; d++) {
        for (int i = 0; i < 300 - d; i++) {
            for (int j = i; j <= i+d; j++) {
                pc[i][i+d][j] = max(pc[i][i+d][j], cows[i][i+d]);
                if (i) pc[i-1][i+d][j] = max(pc[i-1][i+d][j], pc[i][i+d][j]);
                if (i+d < 299) pc[i][i+d+1][j] = max(pc[i][i+d+1][j], pc[i][i+d][j]);
            }
        }
    }

    cout << dp(0, n-1) << '\n';
}
