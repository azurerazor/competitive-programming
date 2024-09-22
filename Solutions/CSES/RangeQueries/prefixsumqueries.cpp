#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll oo = 2e18;
 
struct ST {
    ll val, delta;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = delta = 0;
        if (l == r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    void push() {
        if (lo == hi) return;
        left->delta += delta;
        right->delta += delta;
        delta = 0;
    }
    ll value() { return val + delta; }
    ll query(int l, int r) {
        if (l > hi || r < lo) return -oo;
        if (l <= lo && hi <= r) return value();
        push();
        val = max(left->value(), right->value());
        return max(left->query(l, r), right->query(l,r));
    }
    void update(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) return void(delta += v);
        push();
        left->update(l,r,v);
        right->update(l,r,v);
        val = max(left->value(), right->value());
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<ll> vals(n);
    ST st = ST(0, n);
 
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
        st.update(i+1, n, vals[i]);
    }
 
    while (q--) {
        int t;
        cin >> t;
 
        if (t-1) {
            int a, b;
            cin >> a >> b;
 
            cout << max(0LL, st.query(a, b) - st.query(a-1, a-1)) << '\n';
        } else {
            int i; ll v;
            cin >> i >> v;
            st.update(i, n, -vals[i-1]);
            vals[i-1] = v;
            st.update(i, n, v);
        }
    }
 
    return 0;
}