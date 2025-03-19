#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> subset((1 << 20)), superset, arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        subset[arr[i]]++;
    }

    superset = vector<int>(subset);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 20); j++) {
            if (j & (1 << i)) {
                subset[j] += subset[j ^ (1 << i)];
            } else {
                superset[j] += superset[j ^ (1 << i)];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << subset[arr[i]] << ' ' 
        << superset[arr[i]] << ' ' 
        << (n - subset[(arr[i] ^ ((1 << 20) - 1))]) << '\n';
    }

    return 0;
}