#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

void bfs() {
    vector<int> p(n, 0);
    vector<bool> vis(n, false);

    queue<int> q;

    q.push(0);
    vis[0] = true;

    while (q.size()) {
        int c = q.front();
        q.pop();

        for (auto v : graph[c]) {
            if (!vis[v]) {
                vis[v] = true;
                p[v] = c;
                q.push(v);
            }
        }
    }

    if (!vis[n - 1]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        stack<int> s;
        s.push(n - 1);

        int i = n - 1;
        while(i != p[i]) {
            s.push(p[i]);
            i = p[i];
        }

        cout << s.size() << endl;

        while (s.size()) {
            cout << s.top() + 1 << " ";
            s.pop();
        }

        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    graph = vector<vector<int>>(n);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    return 0;
}