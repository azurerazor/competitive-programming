#include <bits/stdc++.h>
using namespace std;

typedef pair<int, double> pid;

vector<vector<pid>> memo(1001, vector<pid>(2, {-1, 0}));
vector<vector<int>> graph;
vector<double> vals;

pid dp(int v, bool use) {
    if (!graph[v].size()) return {0, 0};
    if (memo[v][use].first != -1) return memo[v][use];

    pid res = {0, 0};

    if (use) {
        for (auto a : graph[v]) {
            pid curr = dp(a, false);
            curr.first++;
            curr.second += min(vals[a], vals[v]);
            for (auto b : graph[v]) {
                if (b==a) continue;
                pid curr2 = max(dp(b, true), dp(b, false));
                curr.first += curr2.first;
                curr.second += curr2.second;
            }
            res = max(res, curr);
        }
    } else {
        for (auto a : graph[v]) {
            pid curr = max(dp(a, true), dp(a, false));
            res.first += curr.first;
            res.second += curr.second;
        }
    }

    return memo[v][use] = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int root = -1;

    map<string, int> m;

    int ind = 0;

    graph = vector<vector<int>>(n);
    vals = vector<double>(n);

    for (int i = 0; i < n; i++) {
        string s1, s2; double d;
        cin >> s1 >> d >> s2;

        if (!m.count(s1)) {
            m[s1] = ind;
            ind++;
        }

        if (!s2.compare("CEO")) {
            root = m[s1];
        } else {
            if (!m.count(s2)) {
                m[s2] = ind;
                ind++;
            }
            graph[m[s2]].push_back(m[s1]);
        }
        vals[m[s1]] = d;
    }

    auto p = max(dp(root, true), dp(root, false));

    cout << p.first << " " << fixed << setprecision(10) << (p.second / p.first) << endl;
}