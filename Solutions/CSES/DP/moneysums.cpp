#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int c;
    cin >> c;
 
    vector<int> coinz(c);
    int sum = 0;
 
    for (int i = 0; i < c; i++) {
        cin >> coinz[i];
        sum += coinz[i];
    }
 
    vector<vector<bool>> dp(c + 1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
 
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                dp[i + 1][j + coinz[i]] = true;
            }
        }
    }
 
    queue<int> q;
 
    for (int i = 1; i < sum + 1; i++) {
        if (dp[c][i]) {
            q.push(i);
        }
    }
 
    cout << q.size() << endl;
 
    while (q.size()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}