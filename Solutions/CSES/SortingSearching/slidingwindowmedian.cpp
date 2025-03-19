#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    multiset<int> s1;
    multiset<int> s2;

    for (int i = 0; i < k-1; i++) {
        s1.insert(v[i]);
    }

    for (int i = k-1; i < n; i++) {
        if (s1.empty() || v[i] <= *(--s1.end())) s1.insert(v[i]);
        else s2.insert(v[i]);
        while (s1.size() > (k+1)/2) {
            auto it = --s1.end();
            s2.insert(*it);
            s1.erase(it);
        }
        while (s1.size() < (k+1)/2) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(it);
        }

        cout << *(--s1.end()) << ' ';
        if (s1.count(v[i-k+1])) s1.erase(s1.find(v[i-k+1]));
        else s2.erase(s2.find(v[i-k+1]));

        while (s1.size() > k/2) {
            auto it = --s1.end();
            s2.insert(*it);
            s1.erase(it);
        }
        while (s1.size() < k/2) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(it);
        }
    }

    cout << '\n';
    return 0;
}