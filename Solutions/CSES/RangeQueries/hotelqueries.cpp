#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct ST {
    const int base = 0;
    int lo, hi, mid, val;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = base;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1, r);
    }
    int query(int v) {
        if (val < v) return -1;
        if (lo==hi) return lo;
        if (v <= left->val) return left->query(v);
        else return right->query(v);
    }
    void update(int i, int v) {
        if (lo==hi) return void(val+=v);
        if (i<=mid) left->update(i,v);
        else right->update(i,v);
        val = max(left->val, right->val);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    ST st = ST(0, n-1);
 
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        st.update(i, a);
    }
 
    while (m--) {
        int s; cin >> s;
        int ans = st.query(s) + 1;
        if (ans) st.update(ans-1, -s);
        cout << ans << ' ';
    }
 
    cout << endl;
    return 0;
}
