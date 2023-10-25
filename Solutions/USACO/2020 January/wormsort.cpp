#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> s;
    int groups;
    void init(int n) {s = vector<int>(n, -1); groups = n;};
    int find(int v) { return ((s[v] < 0) ? v : s[v] = find(s[v]));}
    int size(int v) { return -s[find(v)]; }
    
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b]; s[b] = a;
        groups--;
        return true;
    }
};

int main() {
    ifstream fin;
    fin.open("wormsort.in");
    ofstream fout;
    fout.open("wormsort.out");

    int n, m;
    fin >> n >> m;

    DSU d;
    d.init(n);

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        fin >> cows[i];
        cows[i]--;
    }

    vector<tuple<int, int, int>> wh;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        fin >> a >> b >> w;
        a--; b--;

        wh.push_back({w, a, b});
    }

    sort(wh.begin(), wh.end());

    int ans = -1;
    int j = m - 1;

    for (int i = 0; i < n; i++) {
        while(d.find(i) != d.find(cows[i])) {
            d.join(get<1>(wh[j]), get<2>(wh[j]));
            ans = get<0>(wh[j]);
            j--;
        }
    }

    fout << ans << endl;
}