#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int ans = 0;
 
    multiset<int> s;
 
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (s.lower_bound(a+1) == s.end()) {
            ans++;
        } else {
            s.erase(s.lower_bound(a+1));
        }
        s.insert(a);
    }
 
    cout << ans << '\n';
}