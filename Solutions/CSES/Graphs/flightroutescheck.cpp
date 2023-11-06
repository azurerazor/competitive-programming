#include <bits/stdc++.h>
using namespace std;
 
int bfs(vector<vector<int>>& g) {
    vector<bool> vis(g.size(), false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
 
    while (q.size()) {
        int c = q.front();
        q.pop();
 
        for (auto v : g[c]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
 
    for (int i = 1; i < g.size(); i++) {
        if (!vis[i]) return i+1;
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
    vector<vector<int>> gr(n);
 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
 
    int a = bfs(g);
    if (a) cout << "NO\n" << 1 << ' ' << a << '\n';
    else {
        a = bfs(gr);
        if (a) cout << "NO\n" << a << ' ' << 1 << '\n';
        else cout << "YES\n";
    }
 
    return 0;
}
