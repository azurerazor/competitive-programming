#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> painting;
int memo[301][301];

int dp(int l, int r) {
    if (l >= r) return 1;
    if (memo[l][r] != -1) return memo[l][r];

    int ans = 1e9;

    for (int i = l; i < r; i++) {
        ans = min(ans, dp(l, i) + dp(i+1, r));
    }

    return memo[l][r] = ans - (painting[l] == painting[r]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));

    cin >> n;

    painting = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> painting[i];

    cout << dp(0,n-1) << '\n';
}
