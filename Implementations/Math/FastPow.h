/*
* Source: https://cp-algorithms.com/algebra/binary-exp.html
* Desc: pow function in O(logn) without the innacuracy of std::pow()
* Test: N/A
*/

#pragma once

typedef long long ll;

ll fastPow(ll b, ll p, ll M = 0) {
    ll res = 1;
    while(p) {
        if(p&1) {
            res *= b;
            if (M>0) res %= M;
        }
        b *= b;
        if (M>0) b %= M;
        p >>= 1;
    }
    return res;
}
