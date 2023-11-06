#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<bool> v(n, false);
    v[0] = true;
    int ans = 1;
 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!v[a-1]) ans++;
        v[a] = true;
    }
 
    cout << ans << '\n';
    return 0;
}