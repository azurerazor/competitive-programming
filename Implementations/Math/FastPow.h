/*
* Source: https://cp-algorithms.com/algebra/binary-exp.html
* Desc: pow function in O(logn) without the innacuracy of std::pow()
* Test: N/A
*/

#pragma once

typedef long long ll;

ll fastPow(ll b, ll p) {
    ll res = 1;
    while(p) {
        if(p&1) {
            res *= b; // % MOD
        }
        b *= b; // % MOD
        p >>= 1;
    }
    return res;
}
