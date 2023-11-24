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
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i) {
        if (lo==hi) return void(val++);
        if (i <= mid) left->update(i);
        else right->update(i);
        val = left->val + right->val;
    }
};

int main() {
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int n;
    fin >> n;

    vector<int> order(n);
    for (int i = 0; i < n; i++) fin >> order[i];

    int lidx = -1;
    for (int i = 0; i < n-1; i++) {
        if (order[i] > order[i+1]) lidx = i;
    }

    fout << lidx+1 << '\n';

    ST st = ST(0,n);

    for (int i = lidx+1; i < n; i++) {
        st.update(order[i]);
    }

    for (int i = 0; i <= lidx; i++) {
        ll moves = lidx - i + st.query(0, order[i]-1);
        fout << moves;
        if (i != lidx) fout << ' ';
        st.update(order[i]);
    }
    fout << '\n';

    return 0;
}