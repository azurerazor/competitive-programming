#include <bits/stdc++.h>
using namespace std;
 
#define all(x) begin(x), end(x)
 
struct ST {
    int val;
    int lo, mid, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = 0;
        if (l == r) return;
        left = new ST(l, mid);
        right = new ST(mid+1, r);
    }
    int query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l, r) + right->query(l, r);
    }
    void update(int i, int v) {
        if (lo == hi) return void(val += v);
        if (i <= mid) left->update(i, v);
        else right->update(i, v);
        val = left->val + right->val;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
 
    ST st = ST(0, n-1);
    map<int, int> m;
 
    vector<tuple<int, int, int>> qs;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        qs.emplace_back(v, u, i);
    }
 
    sort(all(qs));
    vector<int> ans(q);
 
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (m.count(v[i])) st.update(m[v[i]], -1);
        m[v[i]] = i;
        st.update(i, 1);
 
        while (p < q && get<0>(qs[p]) == i) {
            auto [r, l, qn] = qs[p];
            ans[qn] = st.query(l, r);
            p++;
        }
    }
 
    for (auto v : ans) cout << v << '\n';
    return 0;
}