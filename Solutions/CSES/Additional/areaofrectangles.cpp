#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, ll> merge(pair<int, ll> a, pair<int, ll> b) {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    return {a.first, a.second + b.second};
}

struct ST {
    pair<int, ll> val;
    ll delta;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l, hi = r;
        mid = (l+r+1)/2;
        val = {0, r-l};
        delta = 0;
        if (r-l-1) {
            left = new ST(lo, mid);
            right = new ST(mid, hi);
        }
    }
    pair<int, ll> value() {
        return {val.first + delta, val.second};
    }
    void prop() {
        left->delta += delta;
        right->delta += delta;
        delta = 0;
    }
    void update(int l, int r, ll v) {
        if (l >= hi || r <= lo) return;
        if (l <= lo && hi <= r) return void(delta += v);
        prop();
        left->update(l, r, v);
        right->update(l, r, v);
        val = merge(left->value(), right->value());
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    ST st = ST(0, 2000001);

    vector<tuple<int, int, int, ll>> updates;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000000;
        y1 += 1000000;
        x2 += 1000000;
        y2 += 1000000;
        updates.emplace_back(x1, y1, y2, 1);
        updates.emplace_back(x2, y1, y2, -1);
    }

    sort(begin(updates), end(updates));

    ll ans = 0;
    int p = 0;
    for (int i = 0; i <= 2000000; i++) {
        while (p < updates.size() && get<0>(updates[p]) == i) {
            auto [x, y1, y2, v] = updates[p];
            st.update(y1, y2, v);
            p++;
        }
        auto [mn, cm] = st.val;
        if (mn == 0) ans += 2000001LL - cm;
    }

    cout << ans << '\n';
    return 0;
}