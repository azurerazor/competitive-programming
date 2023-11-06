#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int n;
    fin >> n;
    vector<int> edges(n, 1);

    int ans = 0;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        ans = max(ans, max(++edges[a], ++edges[b]));
    }

    fout << ans << endl;
    return 0;
}
