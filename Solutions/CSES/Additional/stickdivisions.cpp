#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int x, n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        pq.push(v);
    }

    int ans = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a+b);
    }

    cout << ans << '\n';
    return 0;
}