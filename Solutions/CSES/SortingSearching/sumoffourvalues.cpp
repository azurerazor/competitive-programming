#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;  ll x;
    cin >> n >> x;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<ll, vector<pair<int, int>>> m;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            m[x - v[i] - v[j]].emplace_back(i, j);
            if (m.count(v[i] + v[j])) {
                for (auto& [k, l] : m[v[i]+v[j]]) {
                    if (k != i && k != j && l != i && l != j) {
                        cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}