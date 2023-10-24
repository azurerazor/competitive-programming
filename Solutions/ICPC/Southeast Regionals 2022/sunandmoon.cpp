#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;

    int sun = ys - ds;
    int moon = ym - dm;

    while (sun != moon) {
        if (moon < sun) {
            moon += ym;
        } else {
            sun += ys;
        }
    }

    cout << moon << endl;
}