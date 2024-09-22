#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct ST {
    ll val, tri_d, rect_d;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l, hi = r;
        mid = (l+r)/2;
        val = tri_d = rect_d = 0;
        if (l == r) return;
        left = new ST(l, mid);
        right = new ST(mid+1, r);
    }
    ll value() {
        ll res = rect_d * (hi-lo+1);
        res += tri_d * (hi-lo+1) * (hi-lo+2) / 2;
        return res + val;
    }
    void push() {
        left->rect_d += rect_d;
        right->rect_d += rect_d;
 
        left->tri_d += tri_d;
        right->tri_d += tri_d;
 
        right->rect_d += tri_d * (mid-lo+1);
 
        rect_d = 0;
        tri_d = 0;
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return value();
        push();
        val = left->value() + right->value();
        return left->query(l,r) + right->query(l,r);
    }
    void update(int l, int r, ll v = 1LL) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) {
            tri_d += v;
            rect_d += (lo - l);
            return;
        }
        push();
        left->update(l,r,v);
        right->update(l,r,v);
        val = left->value() + right->value();
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    ST st = ST(0, n-1);
 
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        st.update(i,i,v);
    }
 
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t-1) {
            cout << st.query(a,b) << '\n';
        } else {
            st.update(a,b);
        }
    }
 
    return 0;
}