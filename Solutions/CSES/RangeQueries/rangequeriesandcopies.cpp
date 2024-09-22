#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct ST {
    ll val;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r, ST * lp = NULL, ST * rp = NULL) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l == r) return;
        if (lp == NULL) left = new ST(l, mid);
        else left = lp;
        if (rp == NULL) right = new ST(mid+1, r);
        else right = rp;
    }
    ST * update(int i, ll v) {
        ST * res = NULL;
        if (lo == hi) {
            res = new ST(lo,hi);
            res->val = v;
            return res;
        } 
        if (i <= mid) {
            ST * nlp = left->update(i, v);
            res = new ST(lo,hi,nlp,right);
        } else {
            ST * nrp = right->update(i, v);
            res = new ST(lo,hi,left,nrp);
        }
        res->val = res->left->val + res->right->val;
        return res;
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l, r) + right->query(l,r);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
 
    cin >> n >> q;
 
    vector<ST *> persist(1);
    persist[0] = new ST(0, n-1);
 
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        persist.push_back(persist.back()->update(i, v));
    }
 
    vector<int> arrays;
    arrays.push_back(persist.size() - 1);
 
    while(q--) {
        int t;
        cin >> t;
 
        if (t == 1) {
            int k, a; ll x;
            cin >> k >> a >> x;
            k--; a--;
            persist.push_back(persist[arrays[k]]->update(a, x));
            arrays[k] = persist.size() - 1;
        } else if (t == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            k--; l--; r--;
            cout << persist[arrays[k]]->query(l, r) << '\n';
        } else {
            int k; cin >> k; k--;
            arrays.push_back(arrays[k]);
        }
    }
 
    return 0;
}