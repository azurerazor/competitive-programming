#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 1;
    int tot = 1;

    for (int i = 1; i < s.length(); i++){
        if (s[i]==s[i-1]) {
            tot++;
        } else {
            tot = 1;
        }
        ans = max(ans,tot);
    }

    cout << ans << endl;
}