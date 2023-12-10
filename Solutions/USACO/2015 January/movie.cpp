#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ifstream fin("movie.in");
    ofstream fout("movie.out");

    int n, l;
    fin >> n >> l;

    set<int> s[n];
    vector<int> duration(n);

    for (int i = 0; i < n; i++) {
        int t;
        fin >> duration[i] >> t;

        for (int j = 0; j < t; j++) {
            int v;
            fin >> v;
            s[i].insert(v);
        }

        s[i].insert(1e9);
    }

    vector<int> dp((1 << n));

    int ans = 1e9;

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
                auto t = s[j].upper_bound(dp[i ^ (1 << j)]);
                if (*t == *s[j].begin()) continue;
                t--;
                dp[i] = max(dp[i], *t + duration[j]);
            }
        }

        if (dp[i] >= l) {
            ans = min(ans, __builtin_popcount(i));
        }
    }

    fout << ((ans == 1e9) ? -1 : ans) << '\n';
    return 0;
}
