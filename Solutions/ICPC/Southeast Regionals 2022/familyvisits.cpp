
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int ninf = -1e9;

int n, d;
vector<int> m, c;
vector<bool> visits(1000, false);
int memo[1001][1001];

int dp(int ind, int left) {
    if (left < 0) return inf;
    if (ind < 0) return 0;

    if (memo[ind][left] != ninf) return memo[ind][left];

    int ans = min(max(dp(ind - 1, left - 1) - c[ind] + m[ind], 0), dp(ind - 1, left) + m[ind]);

    if (visits[ind] && ans > 0) {
        return memo[ind][left] = inf;
    }

    return memo[ind][left] = ans;
}

int main() {
    cin >> n >> d;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            memo[i][j] = ninf;
        }
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m.push_back(a);
        c.push_back(b);
    }

    int sd = n;

    for (int i = 0; i < d; i++) {
        int a;
        cin >> a; a--;
        visits[a] = true;
        sd = a;
    }

    int ans = -1;

    for (int i = 0; i <= sd + 1; i++) {
        int curr = dp(sd, i);

        if (curr <= 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}
