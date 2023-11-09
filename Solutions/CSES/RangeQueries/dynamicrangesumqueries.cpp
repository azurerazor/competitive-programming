#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct ST {
    int lo, mid, hi; ll val;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    ll query(int l, int r) {
        if (l>hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i, ll v) {
        if (lo==hi) return void(val=v);
        if (i<=mid) left->update(i,v);
        else right->update(i,v);
        val = left->val + right->val;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    ST st = ST(0,n-1);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        st.update(i,a);
    }
 
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
 
        if (t-1) {
            cout << st.query(a,b-1) << '\n';
        } else {
            st.update(a,b);
        }
    }
 
    return 0;
}
