#include <bits/stdc++.h>
using namespace std;
 
struct ST {
    int val, lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = l;
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
        if (lo==hi) return void(val=lo+v);
        if (i<=mid) left->update(i,v);
        else right->update(i,v);
        val = min(left->val, right->val);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    ST st = ST(0,n-1);
    ST rev = ST(0,n-1);
 
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        st.update(i,v);
        rev.update(n-i-1,v);
    }
 
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
 
        if (t-1) {
            int k; cin >> k;
            k--;
            int left = rev.query(n-k-1, n-1) - (n-k-1);
            int right = st.query(k,n-1) - k;
            cout << min(left, right) << '\n';
        } else {
            int k, v;
            cin >> k >> v;
            k--;
            st.update(k,v);
            rev.update(n-k-1,v);
        }
    }
 
    return 0;
}