#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[20][(1 << 20)];
int n;
vector<int> cows(20);
vector<int> stalls(20);

ll dp(int s, int mask) {
    if (s >= n) return 1;
    if (memo[s][mask] != -1) return memo[s][mask];

    ll res = 0;

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i) && stalls[s] >= cows[i]) res += dp(s+1, mask ^ (1 << i));
    }

    return memo[s][mask] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));

    cin >> n;

    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << dp(0, (1 << n) - 1) << '\n';
    return 0;
}
