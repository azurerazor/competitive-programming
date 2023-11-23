#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    
    int n;
    fin >> n;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) fin >> cows[i];

    sort(cows.rbegin(), cows.rend());

    int p1 = 0, p2 = n-1;

    int ans = 0;

    while (cows[p1] >= ans && p1 <= p2) {
        ans++;
        p1++;

        while (cows[p2] < ans && p2 >= p1) p2--;
    }

    fout << ans << '\n';
    return 0;
}
