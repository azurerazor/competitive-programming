#include <bits/stdc++.h>
using namespace std;
 
int query(vector<vector<int>>& ps, int x1, int y1, int x2, int y2) {
    return ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> ps(n+1, vector<int>(n+1, 0));
 
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            ps[i][j+1] = ps[i][j] + ps[i-1][j+1] - ps[i-1][j];
            if (s[j] == '*') ps[i][j+1]++;
        }
    }
 
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        cout << query(ps, x1, y1, x2, y2) << '\n';
    }
 
    return 0;
}