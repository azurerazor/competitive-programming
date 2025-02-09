#include <bits/stdc++.h>
using namespace std;

int DP[100][100][100];
vector<int> seq;

int dp(int i, int c, int b) {
    if (i == size(seq) - 1) return ((b > 0) ? 1e9 : (c != seq[i]));
    if (DP[i][c][b] != -1) return DP[i][c][b];

    int ans = dp(i+1, c+1, b);
    if (b > 0) ans = min(ans, dp(i+1, 0, b-1));
    return DP[i][c][b] = ans + (c != seq[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, -1, sizeof(DP));

    freopen("taming.in", "r+", stdin);
    freopen("taming.out", "w+", stdout);

    int n;
    cin >> n;

    seq = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> seq[i];

    for (int i = 0; i < n; i++) cout << dp(0, 0, i) << '\n';
    return 0;
}
