#include <bits/stdc++.h>
using namespace std;
 
vector<int> compress;
 
struct ST {
    int lo, mid, hi, val;
    ST * left = nullptr, * right = nullptr;
    ST (int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l != r) {
            left = new ST(lo, mid);
            right = new ST(mid+1, r);
        }
    }
    int query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i, int v) {
        if (lo == hi) return void(val += v);
        if (i <= mid) left->update(i,v);
        else right->update(i,v);
        val = left->val + right->val;
    }
};
 
int idx(int v) {
    return int(lower_bound(compress.begin(), compress.end(), v) - compress.begin());
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    ST st = ST(0, n + 2*q);
 
    vector<int> salaries(n);
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
        compress.push_back(salaries[i]);
    }
 
    vector<tuple<char, int, int>> queries;
 
    while (q--) {
        char t;
        cin >> t;
 
        if (t == '?') {
            int a, b;
            cin >> a >> b;
            compress.push_back(a);
            compress.push_back(b);
            queries.push_back({t, a, b});
        } else {
            int k, x;
            cin >> k >> x;
            k--;
            compress.push_back(x);
            queries.push_back({t, k, x});
        }
    }
 
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
 
    for (int i = 0; i < n; i++) {
        st.update(idx(salaries[i]), 1);
    }
 
    for (auto [t, a, b] : queries) {
        if (t == '?') {
            cout << st.query(idx(a), idx(b)) << '\n';
        } else {
            st.update(idx(salaries[a]), -1);
            st.update(idx(b), 1);
            salaries[a] = b;
        }
    }
 
    return 0;
}