#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef array<array<ll, 2>, 2> matrix;
const ll MOD = 1e9+7;
 
matrix mult(const matrix& m1, const matrix& m2) {
    matrix res;
    res[0] = {0, 0};
    res[1] = {0, 0};
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][k] += m1[i][j] * m2[j][k];
                res[i][k] %= MOD;
            }
        }
    }
 
    return res;
}
 
ll expo(ll p) {
    matrix res, base;
    res[0] = {1, 0};
    res[1] = {0, 0};
    base[0] = {1, 1};
    base[1] = {1, 0};
 
    while (p) {
        if (p&1) {
            res = mult(res, base);
        }
        base = mult(base, base);
        p >>= 1;
    }
 
    return res[0][1];
}
 
int main() {
    ll p;
    cin >> p;
 
    cout << expo(p) << endl;
    return 0;
}