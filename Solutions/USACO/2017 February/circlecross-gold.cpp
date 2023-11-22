#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ST {
    ll val;
    int lo, mid, hi;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (l+r)/2;
        val = 0;
        if(l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i, ll v) {
        if (lo==hi) return void(val = v);
        if (i <= mid) left->update(i,v);
        else right->update(i,v);
        val = left->val + right->val;
    }
};

int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    int n;
    fin >> n;

    ST st = ST(0, 2*n-1);

    vector<int> lastIdx(n, -1);
    int ans = 0;

    for (int i = 0; i < 2*n; i++) {
        int idx; fin >> idx; idx--;
        if (lastIdx[idx] < 0) {
            lastIdx[idx] = i;
            st.update(i, 1);
        } else {
            st.update(lastIdx[idx], 0);
            ans += st.query(lastIdx[idx], i);
        }
    }

    fout << ans << '\n';
    return 0;
}
