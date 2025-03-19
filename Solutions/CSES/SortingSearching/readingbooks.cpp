#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> books(n);
    for (int i = 0; i < n; i++) cin >> books[i];

    sort(begin(books), end(books));

    ll sum = 0;

    for (int i = 0; i < n-1; i++) sum += books[i];

    if (books[n-1] > sum) {
        cout << 2*books[n-1] << '\n';
    } else {
        cout << sum + books[n-1] << '\n';
    }

    return 0;
}