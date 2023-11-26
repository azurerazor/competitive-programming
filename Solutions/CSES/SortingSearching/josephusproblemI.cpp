#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; i++) q.push(i);

    bool f = false;

    while (q.size()) {
        int c = q.front();
        q.pop();

        if (f) cout << c << ' ';
        else q.push(c);
        f = !f;
    }

    cout << endl;
    return 0;
}