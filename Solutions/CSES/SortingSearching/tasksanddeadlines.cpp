#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> v;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    sort(begin(v), end(v));
    ll ans = 0;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        auto [b, a] = v[i];
        t += b;
        ans += a - t;
    }

    cout << ans << '\n';
    return 0;
}