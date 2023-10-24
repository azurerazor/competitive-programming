#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

vector<int> prefSum;

int sum(int l, int r) {
    return prefSum[r] - prefSum[l];
}

int main() {
    int l, h, n;
    cin >> n >> l >> h;

    prefSum.push_back(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefSum.push_back(prefSum[i] + a);
    }

    int minSegs = inf;
    int maxSegs = 0;

    for (int i = l; i <= h; i++) {
        for (int j = i * -1 + 1; j <= 0; j++) {
            int posSegs = 0;

            for (int k = j; k < n; k += i) {
                if (sum(max(0, k), min(k + i, n)) > 0) posSegs++;
            }

            minSegs = min(minSegs, posSegs);
            maxSegs = max(maxSegs, posSegs);
        }
    }

    cout << minSegs << " " << maxSegs << endl;
}