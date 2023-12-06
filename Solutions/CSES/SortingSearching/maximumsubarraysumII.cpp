#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> ps(n+2, 0);

    for (int i = 1; i <= n; i++) {
        ll v; cin >> v;
        ps[i] = ps[i-1] + v;
    }

    multiset<ll> minpfx;
    ll ans = -1e18;

    for (int l = a-b, r = 0; r+a <= n; l++, r++) {
        minpfx.insert(ps[r]);
        if (l > 0) minpfx.erase(minpfx.find(ps[l-1]));
        ans = max(ans, ps[r + a] - *minpfx.begin());
    }

    cout << ans << '\n';
    return 0;
}
