#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n; fin >> n;

    vector<ll> ps(n+1);
    ps[0] = 0;

    for (int i = 1; i <+ n; i++) {
        ll v; fin >> v;
        ps[i] = ps[i-1] + v;
    }

    vector<int> minIdx(7, 2e9), maxIdx(7, -1);

    for (int i = 0; i < n; i++) {
        minIdx[ps[i] % 7] = min(minIdx[ps[i] % 7], i);
        maxIdx[ps[i] % 7] = max(maxIdx[ps[i] % 7], i);
    }

    int ans = 0;

    for (int i = 0; i < 7; i++) ans = max(ans, maxIdx[i] - minIdx[i]);
    
    fout << ans << '\n';
    return 0;
}
