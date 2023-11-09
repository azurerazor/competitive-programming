// lol

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pt;

int main() {
    int p;
    cin >> p;

    set<pt> s;
    vector<pt> pts;

    for (int i = 0; i <p; i++) {
        ll a, b; cin >> a >> b;
        s.insert({a, b});
        pts.push_back({a, b});
    }

    ll ans = 0;

    for (auto [x, y] : pts) {
        if (s.count({x + 2018, y})) ans++;
        if (s.count({x, y+2018})) ans++;
        if (s.count({x+1680, y+1118})) ans++;
        if (s.count({x+1118, y+1680})) ans++;
        if (s.count({x+1680, y-1118})) ans++;
        if (s.count({x+1118, y-1680})) ans++;
    }

    cout << ans << '\n';
    return 0;
}
