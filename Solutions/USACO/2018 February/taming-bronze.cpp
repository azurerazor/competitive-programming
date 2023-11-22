#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    int n;
    fin >> n;

    vector<int> counter(n);
    for (int i = 0; i < n; i++) fin >> counter[i];
    counter[0] = 0;

    for (int i = 1; i < n; i++) {
        if (counter[i] != -1) {
            for (int j = 1; j <= counter[i]; j++) {
                if (counter[i-j] != -1 && counter[i-j] != counter[i] - j) {
                    fout << "-1\n";
                    return 0;
                }
                counter[i-j] = counter[i] - j;
            }
        }
    }

    int minO = 0, maxO = 0;

    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) minO++;
        if (counter[i] == -1) maxO++;
    }

    fout << minO << ' ' << minO+maxO << '\n';
    return 0;
}