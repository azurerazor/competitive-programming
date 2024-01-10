#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> div(1000001, 0);
 
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            div[j]++;
        }
    }
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int c; cin >> c;
 
    while (c--) {
        int a; cin >> a;
        cout << div[a] << '\n';
    }
    return 0;
}