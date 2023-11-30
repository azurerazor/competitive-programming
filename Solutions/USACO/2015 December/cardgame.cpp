#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    int n;
    fin >> n;

    set<int> s;
    for (int i = 1; i <= 2*n; i++) s.insert(i);

    vector<int> opp1(n/2);
    vector<int> opp2(n/2);
    for (int i = 0; i < n/2; i++) {
        fin >> opp1[i];
        s.erase(opp1[i]);
    }
    for (int i = 0; i < n/2; i++) {
        fin >> opp2[i];
        s.erase(opp2[i]);
    }

    sort(opp1.begin(), opp1.end());
    sort(opp2.rbegin(), opp2.rend());

    vector<int> y1(n/2);
    vector<int> y2(n/2);

    for (int i = 0; i < n/2; i++) {
        y2[i] = *s.begin();
        s.erase(s.begin());
    }
    for (int i = 0; i < n/2; i++) {
        y1[i] = *s.begin();
        s.erase(s.begin());
    }

    reverse(y2.begin(), y2.end());

    int p1, p2;
    p1 = p2 = 0;

    for (int i = 0; i < n/2; i++) {
        if (y1[i] > opp1[p1]) {
            p1++;
        }
        if (y2[i] < opp2[p2]) {
            p2++;
        }
    }

    fout << (p1+p2) << '\n';
    return 0;
}
