#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int n;
    fin >> n;

    vector<int> perm(n);

    for (int i = 0; i < n; i++) fin >> perm[i];

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (perm[j] > perm[i]) {
                ans = max(ans, j+1);
            }
        }
    }

    fout << ans << '\n';
    return 0;
}