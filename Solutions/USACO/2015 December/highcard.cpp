#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int n;
    fin >> n;

    set<int> s;
    for (int i = 1; i <= 2*n; i++) s.insert(i);

    vector<int> opp(n);
    for (int i = 0; i < n; i++) {
        fin >> opp[i];
        s.erase(opp[i]);
    }

    sort(opp.begin(), opp.end());

    int p = 0;

    for (int i = 0; i < n; i++) {
        if (*s.begin() > opp[p]) {
            p++;
        }
        s.erase(s.begin());
    }

    fout << p << '\n';
    return 0;
}