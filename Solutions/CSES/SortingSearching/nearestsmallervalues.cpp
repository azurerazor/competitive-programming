#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n; cin >> n;
 
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
 
        while (s.size() && s.top().first >= a) {
            s.pop();
        }
 
        if (s.size()) cout << s.top().second+1 << ' ';
        else cout << "0 ";
        s.push({a, i});
    }
    cout << endl;
    return 0;
}