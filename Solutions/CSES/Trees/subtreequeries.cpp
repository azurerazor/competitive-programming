#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<int> vals;
 
vector<pair<int, int>> tour;
vector<vector<int>> tree;
vector<int> arr;
int ti;
 
void dfs(int a, int p) {
    tour[a].first = ti;
    arr.push_back(vals[a]);
    ti++;
    for (auto v : tree[a]) {
        if (v==p) continue;
        dfs(v, a);
    }
    tour[a].second = ti-1;
}
 
struct ST {
    int lo, mid, hi;
    ll val;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if(l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,hi);
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i, int v) {
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
 
    vals = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    ti = 0;
 
    tree = vector<vector<int>>(n);
    tour = vector<pair<int,int>>(n);
 
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    dfs(0,0);
 
    ST st = ST(0,n-1);
    for (int i = 0; i < n; i++) {
        st.update(i, arr[i]);
    }
 
    while (q--) {
        int t; cin >> t;
 
        if (t-1) {
            int s; cin >> s; s--;
            cout << st.query(tour[s].first, tour[s].second) << '\n';
        } else {
            int s, x;
            cin >> s >> x;
            s--;
            st.update(tour[s].first,x);
        }
    }
 
    return 0;
}
