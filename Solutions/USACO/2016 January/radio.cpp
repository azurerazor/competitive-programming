#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> FJ;
vector<array<int, 2>> Bessie;
int n, m;
vector<vector<int>> memo(1001, vector<int>(1001, -1));

int dist2(array<int, 2> a, array<int, 2> b) {
    return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
}

int dp(int idxf, int idxb) {
    if (idxf >= n && idxb >= m) return 0;
    if (memo[idxf][idxb] != -1) return memo[idxf][idxb];

    int res = 2e9;
    if (idxf < n) res = min(res, dp(idxf+1, idxb) + dist2(FJ[idxf+1], Bessie[idxb]));
    if (idxb < m) res = min(res, dp(idxf, idxb+1) + dist2(FJ[idxf], Bessie[idxb+1]));
    if (idxf < n && idxb < m) res = min(res, dp(idxf+1, idxb+1) + dist2(FJ[idxf+1], Bessie[idxb+1]));

    return memo[idxf][idxb] = res;
}

int main() {
    ifstream fin("radio.in");
    ofstream fout("radio.out");

    fin >> n >> m;

    FJ = vector<array<int, 2>>(n+1);
    Bessie = vector<array<int, 2>>(m+1);
    fin >> FJ[0][0] >> FJ[0][1] >> Bessie[0][0] >> Bessie[0][1];

    string fjs, bs;
    fin >> fjs >> bs;

    for (int i = 1; i <= n; i++) {
        FJ[i] = FJ[i-1];
        if (fjs[i-1] == 'E') FJ[i][0]++;
        if (fjs[i-1] == 'W') FJ[i][0]--;
        if (fjs[i-1] == 'N') FJ[i][1]++;
        if (fjs[i-1] == 'S') FJ[i][1]--;
    }

    for (int i = 1; i <= m; i++) {
        Bessie[i] = Bessie[i-1];
        if (bs[i-1] == 'E') Bessie[i][0]++;
        if (bs[i-1] == 'W') Bessie[i][0]--;
        if (bs[i-1] == 'N') Bessie[i][1]++;
        if (bs[i-1] == 'S') Bessie[i][1]--;
    }

    fout << dp(0,0) << '\n';
    return 0;
}
