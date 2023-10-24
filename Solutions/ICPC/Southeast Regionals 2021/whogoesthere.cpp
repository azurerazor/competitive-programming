#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v;
    int teams[m];
    int sum = 0;

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        v.push_back(b);
        sum += b;
        teams[i] = 0;
    }

    if (sum > n) {
        for (int i = 0; i < n; i++) {
            if (v[i % m] == 0) {
                n++;
                continue;
            }

            v[i % m]--;
            teams[i % m]++;
        }
    } else {
        for (int i = 0; i < m; i++) {
            teams[i] = v[i];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << teams[i] << endl;
    }
}