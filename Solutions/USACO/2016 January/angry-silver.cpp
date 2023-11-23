#include <bits/stdc++.h>
using namespace std;

int numCows(vector<int>& cows, int r) {
    int ans = 1;
    int p = cows[0];

    for (int i = 1; i < cows.size(); i++) {
        if (cows[i] - p > 2*r) {
            ans++;
            p = cows[i];
        }
    }

    return ans;
}

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int n, k;
    fin >> n >> k;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) fin >> cows[i];
    
    sort(cows.begin(), cows.end());

    int l = 0, r = 1e9+5;

    while (l != r) {
        int m = l + (r-l)/2;

        if (numCows(cows, m) <= k) {
            r = m;
        } else {
            l = m+1;
        }
    }

    fout << l << '\n';
    return 0;
}