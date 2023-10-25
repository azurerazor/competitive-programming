#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

bool isValid(int x, int y, int l) {
    return x >= 0 && y >= 0 && x < l && y < l;
}

int main() {
    int n;

    cin >> n;

    vector<string> v;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }

    vector<vector<ll>> paths(n, vector<ll>(n, 0));
    paths[0][0] = (v[0][0] == '.');

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '.') {
                if (isValid(i-1, j, n)) {
                    paths[i][j] += paths[i-1][j];
                    paths[i][j] %= MOD;
                }

                if (isValid(i, j-1, n)) {
                    paths[i][j] += paths[i][j-1];
                    paths[i][j] %= MOD;
                }
            }
        }
    }

    cout << paths[n - 1][n - 1] << endl;
    return 0;
}