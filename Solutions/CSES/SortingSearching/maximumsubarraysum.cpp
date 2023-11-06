#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long tot = 0;
    long long ans = -1e16;
 
    for (int i = 0; i < n; i++) {
        long long a; cin >> a; tot += a;
        ans = max(ans, tot);
        if (tot < 0) tot = 0;
    }
 
    cout << ans << endl;
}