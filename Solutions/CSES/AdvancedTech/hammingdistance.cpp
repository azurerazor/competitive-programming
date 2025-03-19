#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < k; j++) {
            arr[i] = (arr[i] << 1) | (int)(s[j] == '1');
        }
    }

    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) ans = min(ans, __builtin_popcount(arr[i] ^ arr[j]));
    }

    cout << ans << '\n';
}