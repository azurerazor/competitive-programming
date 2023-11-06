#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> s(n);
    vector<int> l(n);
 
    for (int i = 0; i < n; i++) cin >> s[i] >> l[i];
 
    sort(s.begin(), s.end());
    sort(l.begin(), l.end());
 
    int p1 = 0;
    int p2 = 0;
    int tot = 0;
    int ans = 0;
 
    while (p1 < n) {
        if(s[p1] < l[p2]) {
            tot++;
            p1++;
            ans = max(ans, tot);
        } else {
            tot--;
            p2++;
        }
    }
 
    cout << ans << '\n';
    return 0;
}