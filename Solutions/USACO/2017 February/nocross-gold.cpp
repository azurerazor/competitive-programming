#include <bits/stdc++.h>
using namespace std;

vector<int> s1, s2;
vector<vector<int>> memo(1001, vector<int>(1001, -1));
int n;

int dp(int i1, int i2) {
    if (i1 >= n || i2 >= n) return 0;
    if (memo[i1][i2] != -1) return memo[i1][i2];

    int res = max(dp(i1+1, i2), dp(i1, i2+1));

    if (abs(s1[i1] - s2[i2]) <= 4) res = max(res, dp(i1+1, i2+1) + 1);
    
    return memo[i1][i2] = res;
}

int main() {
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");

    fin >> n;

    s1 = s2 = vector<int>(n);
    for (int i = 0; i < n; i++) fin >> s1[i];
    for (int i = 0; i < n; i++) fin >> s2[i];

    fout << dp(0, 0) << '\n';
}