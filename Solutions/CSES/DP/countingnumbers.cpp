#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string num;
 
ll DP[2][2][10][20];
 
ll dp(bool start, bool match, int prev, int idx) {
    if (idx == num.length()) return 1;
    if (DP[start][match][prev][idx] != -1) return DP[start][match][prev][idx];
 
    ll ans = 0;
    int dig = (num[idx] - '0');
 
    for (int i = 0; i < 10; i++) {
        if (match && i > dig) break;
        if (i == prev && start) continue;
        ans += dp(max(start, i > 0), min(match, i == dig), i, idx+1);
    }
 
    return DP[start][match][prev][idx] = ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, -1, sizeof(DP));
 
    ll f;
    cin >> f;
    num = to_string(f-1);
 
    ll ans = ((f == 0) ? 0 : -dp(0, 1, 0, 0));
 
    cin >> num;
    memset(DP, -1, sizeof(DP));
    ans += dp(0, 1, 0, 0);
 
    cout << ans << '\n';
    return 0;
}