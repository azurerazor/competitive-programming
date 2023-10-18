#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> memo(501, vector<int>(501, -1));
const int inf = 1e9;
 
int dp(int a, int b) {
    if (a < b) swap(a, b);
    if (a == b) return 0;
 
    if (memo[a][b] != -1) return memo[a][b];
 
    int minm = inf;
 
    for (int i = 1; i <= a / 2; i++) {
        minm = min(minm, dp(i, b) + dp(a - i, b) + 1);
    }
 
    for (int i = 1; i <= b / 2; i++) {
        minm = min(minm, dp(i, a) + dp(b - i, a) + 1);
    }
 
    return memo[a][b] = minm;
}
 
int main() {
    int a, b;
    cin >> a >> b;
 
    cout << dp(a, b) << endl;
}
