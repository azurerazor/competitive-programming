#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int DBUG = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; ll x;
    cin >> n >> x;

    vector<ll> s(n), f(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    deque<pair<ll, ll>> hull;
    deque<ll> range;
    hull.emplace_back(x, 0);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        while (range.size() && range.front() < s[i]) {
            hull.pop_front();
            range.pop_front();
        }
        auto [m, b] = hull.front();
        ans = m * s[i] + b;
        
        if (hull.back().first == f[i]) continue;
        while (range.size()) {
            auto [m2, b2] = hull.back();
            int inter = (ans - b2) / (m2 - f[i]);
            if (inter <= range.back()) {
                hull.pop_back();
                range.pop_back();
            } else break;
        }
        auto [m2, b2] = hull.back();
        int inter = (ans - b2) / (m2 - f[i]);
        range.push_back(inter);
        hull.emplace_back(f[i], ans);
    }

    cout << ans << '\n';
    return 0;
}