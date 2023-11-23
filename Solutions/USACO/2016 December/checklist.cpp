#include <bits/stdc++.h>
using namespace std;

int memo[1001][1001][2];
vector<array<int, 2>> H;
vector<array<int, 2>> G;
int h, g;

int dist2(array<int, 2> a, array<int, 2> b) {
    return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
}

int dp(int hi, int gi, bool isH) {
    if (hi >= h && gi >= g) return (isH ? 0 : 2e9);

    if (memo[hi][gi][isH] != -1) return memo[hi][gi][isH];

    array<int, 2> curr;
    if (isH) {
        curr = H[hi-1];
    } else {
        curr = G[gi-1];
    }

    int res = 2e9;
    if (hi < h) res = min(res, dp(hi+1, gi, 1) + dist2(curr, H[hi]));
    if (gi < g) res = min(res, dp(hi, gi+1, 0) + dist2(curr, G[gi]));

    return memo[hi][gi][isH] = res;
}

int main() {
    memset(memo, -1, sizeof(memo));
    ifstream fin("checklist.in");
    ofstream fout("checklist.out");


    fin >> h >> g;
    H = vector<array<int, 2>>(h);
    G = vector<array<int, 2>>(g);

    for (int i = 0; i < h; i++) fin >> H[i][0] >> H[i][1];
    for (int i = 0; i < g; i++) fin >> G[i][0] >> G[i][1];

    fout << dp(1,0,1) << '\n';
    return 0;
}