#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
 
    int p; cin >> p;
    long long tot = 0;
 
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        tot += max(0, p-a);
        p = max(p,a);
    }
 
    cout << tot << '\n';
    return 0;
}