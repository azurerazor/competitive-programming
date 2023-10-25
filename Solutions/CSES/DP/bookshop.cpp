#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> pr;
    vector<int> pg;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pr.push_back(a);
    }
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pg.push_back(a);
    }
 
    vector<vector<int>> dp(2, vector<int>(x + 1, -1));
    vector<int> v;
 
    dp[0][x] = 0;
 
    int maxi = 0;
 
    int a = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (dp[a][j] != -1) {
                dp[1 - a][j] = max(dp[1 - a][j], dp[a][j]);
 
                if (j - pr[i] >= 0) {
                    dp[1 - a][j - pr[i]] = max(dp[a][j] + pg[i], dp[1 - a][j - pr[i]]);
                    maxi = max(maxi, dp[1 - a][j - pr[i]]);
                }
            }
        }
 
        a = 1 - a;
    }
 
    cout << maxi << endl;
    
}