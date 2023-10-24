#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll h, k, v, s;
    cin >> h >> k >> v >> s;
    ll x = 0;

    while (h > 0) {
        v += s;
        v -= max(1LL, v / 10);

        if (v >= k) {
            h++;
        }

        if (0 < v && v < k) {
            h--;
            if (h == 0) v = 0;
        }

        if (v <= 0) {
            h = 0;
            v = 0;
        }
        x += v;
        if (s > 0) s--;
    }

    cout << x << endl;
}