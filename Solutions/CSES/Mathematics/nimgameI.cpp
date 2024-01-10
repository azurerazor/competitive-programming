#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n; cin >> n;
        int XOR = 0;
 
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            XOR ^= a;
        }
 
        cout << (!(XOR) ? "second\n" : "first\n");
    }
}