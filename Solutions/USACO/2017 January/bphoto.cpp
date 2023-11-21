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
        if (lo==hi) return void(val += v);
        if (i <= mid) left->update(i,v);
        else right->update(i,v);
        val = left->val + right->val;
    }
};

int main() {
    ifstream fin("bphoto.in");
    ofstream fout("bphoto.out");

    int n; fin >> n;
    vector<int> arr(n), sarr(n);

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        sarr[i] = arr[i];
    }

    sort(sarr.begin(), sarr.end());

    map<int, int> compress;
    int hi = 0;
    for (int i = 0; i < n; i++) {
        if (!compress.count(sarr[i])) {
            compress[sarr[i]] = hi++;
        }
    }

    ST left = ST(0,hi);
    ST right = ST(0,hi);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        right.update(compress[arr[i]], 1);
    }

    for (int i = 0; i < n; i++) {
        int v = compress[arr[i]];
        left.update(v, 1);
        right.update(v, -1);

        ll lq = left.query(v+1, hi);
        ll rq = right.query(v+1, hi);

        if (max(lq, rq) > min(lq,rq)*2) ans++;
    }

    fout << ans << '\n';
    return 0;
}
