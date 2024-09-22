#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ST {
    int lo, hi, mid;
    ll sum, maxSum, maxPref, maxSuf;
    ST *left, *right;
    ST(int l, int r) {
        lo = l; hi = r;
        mid = (lo+hi)/2;
        sum = maxSum = maxPref = maxSuf = 0;
        if (l==r) return;
        left = new ST(l,mid);
        right = new ST(mid+1,r);
    }
    void update(int i, int v) {
        if (lo==hi) {
            sum = maxPref = maxSuf = v;
            maxSum = max(v,0);
            return;
        }
        if(i<=mid) left->update(i,v);
        else right->update(i,v);
        merge();
    }
    void merge() {
        sum = left->sum + right->sum;
        maxSum = max(left->maxSuf + right->maxPref, max(left->maxSum, right->maxSum));
        maxPref = max(left->maxPref, left->sum + right->maxPref);
        maxSuf = max(right->maxSuf, right->sum + left->maxSuf);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    ST st = ST(0, n-1);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        st.update(i,v);
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        i--;
        st.update(i, v);
        cout << st.maxSum << '\n';
    }

    return 0;
}