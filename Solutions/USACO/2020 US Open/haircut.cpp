#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct STRS {
    // point update range sum
    ll val;
    int lo, mid, hi;
    STRS *left, *right;
    STRS(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l==r) return;
        left = new STRS(l,mid);
        right = new STRS(mid+1,r);
    }
    ll query(int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l <= lo && hi <= r) return val;
        return left->query(l,r) + right->query(l,r);
    }
    void update(int i) {
        if (lo == hi) return void(val++);
        if (i <= mid) left->update(i);
        else right->update(i);
        val = left->val + right->val;
    }
};

struct STPQ {
    // range update point sum
    ll val;
    int lo, mid, hi;
    STPQ *left, *right;
    STPQ(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        val = 0;
        if (l==r) return;
        left = new STPQ(l,mid);
        right = new STPQ(mid+1,r);
    }
    ll query(int i) {
        if (lo==hi) return val;
        if (i <= mid) return left->query(i) + val;
        return right->query(i) + val;
    }
    void update(int l, int r, ll v) {
        if (l > hi || r < lo) return;
        if (l <= lo && hi <= r) return void(val += v);
        left->update(l,r,v);
        right->update(l,r,v);
    }
};

int main() {
    ifstream fin("haircut.in");
    ofstream fout("haircut.out");

    int n; fin >> n;

    STRS st1 = STRS(0,n+1);
    STPQ st2 = STPQ(0,n+1);

    for (int i = 0; i < n; i++) {
        int a; fin >> a;
        ll inv = st1.query(a+1, n+1);
        st1.update(a);
        st2.update(a+1,n+1,inv);
    }

    for (int i = 0; i < n; i++) {
        fout << st2.query(i) << '\n';
    }

    return 0;
}
