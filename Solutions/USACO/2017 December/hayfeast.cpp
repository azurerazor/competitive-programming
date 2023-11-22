#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");

    int n; ll m;
    fin >> n >> m;

    vector<ll> flavors(n);
    vector<ll> spiciness(n);

    for (int i = 0; i < n; i++) fin >> flavors[i] >> spiciness[i];

    ll ans = 2e9;
    ll sum = 0;

    multiset<ll> window;

    for (int l = 0, r = 0; r < n; l++) {
        while (r < n && sum < m) {
            sum += flavors[r];
            window.insert(spiciness[r]);
            r++;
        }

        if (sum >= m) ans = min(ans, *window.rbegin());
        sum -= flavors[l];
        window.erase(window.find(spiciness[l]));
    }

    fout << ans << '\n';
    return 0;
}
