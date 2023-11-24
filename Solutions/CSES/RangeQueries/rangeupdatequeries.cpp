#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct ST {
    ll val;
    int lo, mid, hi;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    ll query(int i) {
        if (lo==hi) return val;
        if (i <= mid) return left->query(i)+val;
        return right->query(i)+val;
    }
    void update(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) return void(val+=v);
        left->update(l,r,v);
        right->update(l,r,v);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    ST st = ST(0,n-1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        st.update(i,i,a);
    }
 
    while (q--) {
        int t; cin >> t;
        if (t-1) {
            int a; cin >> a;
            cout << st.query(a-1) << '\n';
        } else {
            int a, b, u;
            cin >> a >> b >> u;
            st.update(a-1,b-1,u);
        }
    }
 
    return 0;
}