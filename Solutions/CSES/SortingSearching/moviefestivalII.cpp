#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> times(n);

    for (int i = 0; i < n; i++) cin >> times[i].second >> times[i].first;

    sort(times.begin(), times.end());

    multiset<int> s;
    s.insert(-1);
    for (int i = 0; i < k; i++) s.insert(0);

    int ans = 0;

    for (auto [e,st] : times) {
        int val = *(--s.upper_bound(st));
        if (val == -1) continue;
        ans++;
        s.erase(s.find(val));
        s.insert(e);
    }

    cout << ans << '\n';
    return 0;
}