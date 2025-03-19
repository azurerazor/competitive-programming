#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) (ll)size(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    multiset<ll> s1;
    multiset<ll> s2;

    ll t1 = 0, t2 = 0;

    for (int i = 0; i < k-1; i++) {
        s1.insert(v[i]);
        t1 += v[i];
    }

    for (int i = k-1; i < n; i++) {
        if (s1.empty() || v[i] <= *(--s1.end())) {
            s1.insert(v[i]);
            t1 += v[i];
        } else {
            s2.insert(v[i]);
            t2 += v[i];
        }
        while (sz(s1) > (k+1)/2) {
            auto it = --s1.end();
            ll val = *it;
            s2.insert(*it);
            t2 += val;
            s1.erase(it);
            t1 -= val;
        }
        while (sz(s1) < (k+1)/2) {
            auto it = s2.begin();
            ll val = *it;
            s1.insert(*it);
            t1 += val;
            s2.erase(it);
            t2 -= val;
        }

        ll med = *(--s1.end());

        cout << t2 - med * sz(s2) + med * sz(s1) - t1 << ' ';
        if (s1.count(v[i-k+1])) {
            s1.erase(s1.find(v[i-k+1]));
            t1 -= v[i-k+1];
        } else {
            s2.erase(s2.find(v[i-k+1]));
            t2 -= v[i-k+1];
        }

        while (sz(s1) > (k)/2) {
            auto it = --s1.end();
            ll val = *it;
            s2.insert(*it);
            t2 += val;
            s1.erase(it);
            t1 -= val;
        }
        while (sz(s1) < (k)/2) {
            auto it = s2.begin();
            ll val = *it;
            s1.insert(*it);
            t1 += val;
            s2.erase(it);
            t2 -= val;
        }
    }

    cout << '\n';
    return 0;
}