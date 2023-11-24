#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> memo(5000, vector<int>(5000, -1));
 
string s1, s2;
 
int dp(int s1i, int s2i) {
    if (s2i >= s2.length()) return s1.length() - s1i;
    if (s1i >= s1.length()) return s2.length() - s2i;
 
    if (memo[s1i][s2i] != -1) return memo[s1i][s2i];
 
    int res = min(min(dp(s1i+1, s2i) + 1, dp(s1i, s2i+1)+1), dp(s1i+1, s2i+1) + !(s1[s1i] == s2[s2i]));
 
    if (s1[s1i] == s2[s2i]) res = min(res, dp(s1i+1, s2i+1));
 
    return memo[s1i][s2i] = res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> s1 >> s2;
 
    cout << dp(0,0) << '\n';
}
