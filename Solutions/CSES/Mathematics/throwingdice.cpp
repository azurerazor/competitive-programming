#include <bits/stdc++.h>
using namespace std;
 
// new6 = 6+5+4+3+2+1
// new5 = 6
// new4 = 5
// new3 = 4
// new2 = 3
// new1 = 2
 
/*
1 1 1 1 1 1
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
*/
 
typedef long long ll;
const ll MOD = 1e9+7;
 
struct Matrix {
    vector<vector<ll>> m;
    int sz;
    Matrix(int n) { m = vector<vector<ll>>(n, vector<ll>(n)); sz = n; }
    Matrix operator *(Matrix b) {
        Matrix res(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    res.m[i][k] += m[i][j] * b.m[j][k];
                    res.m[i][k] %= MOD;
                }
            }
        }
        return res;
    }
};
 
ll expo(ll p) {
    Matrix res(6);
    res.m[0][0] = 1;
    Matrix b(6);
    for (int i = 0; i < 6; i++) b.m[0][i] = 1;
    for (int i = 1; i < 6; i++) b.m[i][i-1] = 1;
 
    while (p) {
        if (p&1) res = res * b;
        b = b * b;
        p >>= 1;
    }
 
    return res.m[0][0];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll k;
    cin >> k;
 
    cout << expo(k) << '\n';
    return 0;
}