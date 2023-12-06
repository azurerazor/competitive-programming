#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t, p;
    cin >> t >> p;

    multiset<int> tix;
    tix.insert(-1);

    for (int i = 0; i < t; i++) {
        int v; cin >> v;
        tix.insert(v);
    }

    for (int i = 0; i < p; i++) {
        int v; cin >> v;
        int pr = *(--tix.upper_bound(v));
        cout << pr << ' ';
        if (pr != -1) tix.erase(tix.find(pr));
    }

    cout << endl;
    return 0;
}