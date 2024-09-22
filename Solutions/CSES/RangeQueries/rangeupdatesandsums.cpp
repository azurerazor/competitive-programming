#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct ST {
    ll sdelta, adelta, val;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = sdelta = adelta = 0;
        if (l == r) return;
        left = new ST(l,mid);
        right = new ST(mid+1, r);
    }
    ll value() {
        if (adelta > 0) {
            return (adelta + sdelta) * (hi-lo+1);
        }
        return val + sdelta * (hi-lo+1);
    }
    void push() {
        if (adelta != 0) {
            left->adelta = adelta;
            left->sdelta = sdelta;
            right->adelta = adelta;
            right->sdelta = sdelta;
        } else {
            left->sdelta += sdelta;
            right->sdelta += sdelta;
        }
        adelta = sdelta = 0;
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return value();
        push();
        val = left->value() + right->value();
        return left->query(l, r) + right->query(l,r);
    }
    void set(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) {
            adelta = v;
            sdelta = 0;
            return;
        }
        push();
        left->set(l,r,v);
        right->set(l,r,v);
        val = left->value() + right->value();
    }
    void add(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) return void(sdelta += v);
        push();
        left->add(l,r,v);
        right->add(l,r,v);
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
        st.set(i,i,v);
    }
 
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
 
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            st.add(a-1,b-1,x);
        } else if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            st.set(a-1,b-1,x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << st.query(a-1,b-1) << '\n';
        }
    }
 
    return 0;
}