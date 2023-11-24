#include <bits/stdc++.h>
using namespace std;
 
struct ST {
    int lo, mid, hi, val;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 2e9;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    int query(int l, int r) {
        if (l > hi || r < lo) return 2e9;
        if (l <= lo && hi <= r) return val;
        return min(left->query(l,r), right->query(l,r));
    }
    void update(int i, int v) {
        if (lo==hi) return void(val=v);
        if (i<=mid) left->update(i,v);
        else right->update(i,v);
        val = min(left->val, right->val);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q; cin >> n >> q;
 
    ST st = ST(0,n-1);
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        st.update(i,v);
    }
 
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t-1) {
            cout << st.query(a-1,b-1) << '\n';
        } else {
            st.update(a-1,b);
        }
    }
    return 0;
}