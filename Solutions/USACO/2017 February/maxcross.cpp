#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    int n, k, b;

    fin >> n >> k >> b;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < b; i++) {
        int v;
        fin >> v;
        pq.push(v);
    }

    vector<int> ps(n+1,0);

    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1] + 1;

        if (pq.size() && pq.top() == i) {
            ps[i]--;
            pq.pop();
        }
    }

    int ans = 0;

    for (int p1 = 0, p2 = k; p2 <= n; p1++, p2++) {
        ans = max(ans, ps[p2]-ps[p1]);
    }

    fout << k-ans << '\n';
    return 0;
}