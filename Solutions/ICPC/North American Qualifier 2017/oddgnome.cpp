#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> orig(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; i++) {
        cin >> orig[i];
    }

    sort(sorted.begin(), sorted.end());

    for (int i = 1; i < n; i++) {
        if (orig[i] < orig[i-1]) {
            cout << i + ((i != n-1) && orig[i-1] < orig[i+1]) << '\n';
            break;
        }
    }
}

int main() {
    int g;
    cin >> g;

    while (g--) solve();
}