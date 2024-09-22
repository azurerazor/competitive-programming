#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    vector<ll> S(1000000), W(1000000);

    S[0] = W[0] = 1;

    for (int i = 1; i < 1000000; i++) {
        S[i] = 4 * S[i-1] + W[i-1];
        S[i] %= MOD;
        W[i] = 2 * W[i-1] + S[i-1];
        W[i] %= MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int v;
        cin >> v;

        cout << (S[v-1] + W[v-1]) % MOD << '\n';
    }

    return 0;
}