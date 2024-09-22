#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n), ps(n+1);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ps[i+1] = ps[i] + v[i];
    }

    vector<vector<int>> par(20, vector<int>(n));
    vector<vector<ll>> sum(20, vector<ll>(n));
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (s.size() && v[s.top()] < v[i]) {
            int j = s.top();
            s.pop();
            par[0][j] = i;
            sum[0][j] = v[j] * (ll)(i-j) - ps[i] + ps[j];
        }

        s.push(i);
    }

    while (s.size()) {
        par[0][s.top()] = s.top();
        s.pop();
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < n; i++) {
            par[j][i] = par[j-1][par[j-1][i]];
            sum[j][i] = sum[j-1][i] + sum[j-1][par[j-1][i]];
        }
    }

    while (k--) {
        int l, r;
        cin >> l >> r;
        l--;

        ll ans = 0;
        for (int i = 19; i >= 0; i--) {
            if (par[i][l] < r) {
                ans += sum[i][l];
                l = par[i][l];
            }
        }

        ans += v[l] * (ll)(r-l) - ps[r] + ps[l];
        cout << ans << '\n';
    }

    return 0;
}