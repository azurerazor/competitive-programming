#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, k;
    cin >> n >> k;
 
    vector<int> moves(k);
    for (int i = 0; i < k; i++) cin >> moves[i];
    sort(moves.begin(), moves.end());
 
    vector<bool> states(n+1, false);
    for (int i = 0; i <= n; i++) {
        if (!states[i]) {
            for (int j : moves) {
                if (i + j <= n) {
                    states[i+j] = true;
                } else {
                    break;
                }
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        cout << ((states[i]) ? "W" : "L");
    }
    cout << '\n';
    return 0;
}