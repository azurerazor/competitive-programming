#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    fin >> n;

    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; i++) {
        int q, t;
        fin >> q >> t;
        pairs.push_back({t, q});
    }

    sort(pairs.begin(), pairs.end());

    int ans = 0;

    int p1 = 0, p2 = n-1;

    while (p1 < p2) {
        ans = max(ans, pairs[p1].first + pairs[p2].first);
        int diff = min(pairs[p1].second, pairs[p2].second);
        pairs[p1].second -= diff;
        pairs[p2].second -= diff;

        if (pairs[p1].second == 0) p1++;
        if (pairs[p2].second == 0) p2--;
    }

    if (pairs[p1].second > 0) ans = max(ans, pairs[p1].first*2);

    fout << ans << '\n';
    return 0;
}
