#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int memo[300000][3][8];
vector<int> tasks(300000);

bool on(int mask, int bit) {
    return ((mask & (1 << bit)) == (1 << bit));
}

int dp(int ind, int tool, int mask) {
    if (ind >= n) return 0;
    if (mask == 0) return 0;
    if (memo[ind][tool][mask] != -1) return memo[ind][tool][mask];

    if (tasks[ind] == tool) {
        return memo[ind][tool][mask] = dp(ind + 1, tool, mask) + 1;
    } else {
        int res = dp(ind + 1, tool, mask);

        for (int i = 0; i < 3; i++) {
            if (on(mask, i) && i != tool) {
                res = max(res, dp(ind, i, (mask ^ (1 << tool))));
            }
        }

        return memo[ind][tool][mask] = res;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }

    int ans = max(dp(0, 0, 7), max(dp(0, 1, 7), dp(0, 2, 7)));

    cout << ans << endl;
}