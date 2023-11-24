#include <bits/stdc++.h>
using namespace std;
 
bool comp(array<int, 3> i, array<int, 3> j) {
    if (i[0] != j[0]) return ((i[0] < j[0]) ? 1 : 0);
    return ((i[1] > j[1]) ? 1 : 0);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
 
    vector<array<int, 3>> pts2(n);
 
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pts2[i] = {b, a, i};
    }
 
    vector<bool> ans1(n), ans2(n);
 
    sort (pts2.begin(), pts2.end(), comp);
    int maxl = 0;
    for (int i = 0; i < n; i++) {
        if (pts2[i][1] <= maxl) ans1[pts2[i][2]] = true;
        maxl = max(maxl, pts2[i][1]);
    }
 
    reverse(pts2.begin(), pts2.end());
    int minl = 1e9;
    for (int i = 0; i < n; i++) {
        if (pts2[i][1] >= minl) ans2[pts2[i][2]] = true;
        minl = min(minl, pts2[i][1]);
    }
 
    for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
    cout << endl;
    return 0;
}