#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<pair<int, int>> v;
 
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        v.push_back({a, i});
    }
 
    sort(v.begin(), v.end());
    int p1 = 0, p2 = n-1;
 
    while (p1 != p2) {
        int sum = v[p1].first + v[p2].first;
        if (sum == x) {
            cout << v[p1].second << ' ' << v[p2].second << '\n';
            break;
        }
        p1 += (sum < x);
        p2 -= (sum > x);
    }
 
    if (p1 == p2) cout << "IMPOSSIBLE\n";
    return 0;
}