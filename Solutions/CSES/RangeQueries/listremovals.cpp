#include <bits/stdc++.h>
using namespace std;
 
struct ST {
    int val;
    int lo, mid, hi;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = 0;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    int query(int k) {
        if (lo==hi) return lo;
        if (left->val >= k) return left->query(k);
        else return right->query(k-left->val);
    }
    void update(int i) {
        if (lo==hi) return void(val = 1-val);
        if (i <= mid) left->update(i);
        else right->update(i);
        val = left->val + right->val;
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    vector<int> v(n);
    ST st = ST(0,n-1);
 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.update(i);
    }
 
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int j = st.query(k);
        cout << v[j] << ' ';
        st.update(j);
    }
    cout << endl;
    return 0;
}