#include <bits/stdc++.h>
using namespace std;
 
struct sparseTable {
    vector<vector<int>> ST;
    int sz;
    int csz;
    sparseTable(vector<int> v) {
        sz = v.size();
        csz = __lg(sz) + 2;
        ST = vector<vector<int>>(sz, vector<int>(csz, 1e9));
        for (int i = 0; i < sz; i++) {
            ST[i][0] = v[i];
        }
        for (int i = 1; i < csz; i++) {
            for (int j = 0; j + (1<<i) <= sz; j++) {
                ST[j][i] = min(ST[j][i-1], ST[j + (1 << (i-1))][i-1]);
            }
        }
    }
    int query(int l, int r) {
        int lgg = __lg(r-l+1);
        return min(ST[l][lgg], ST[r - (1 << lgg) + 1][lgg]);
    }
};
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sparseTable st = sparseTable(v);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << st.query(a,b) << '\n';
    }
}
