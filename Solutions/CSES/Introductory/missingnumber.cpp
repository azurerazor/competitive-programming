#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    set<int> s;

    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (int i = 0; i < n-1; i++) {
        int a; cin >> a; s.erase(a);
    }

    cout << *s.begin() << endl;
    return 0;
}