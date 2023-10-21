#include <bits/stdc++.h>
using namespace std;

void topSort(vector<int> v[], int ind[], int n) {
    queue<int> q;
    stack<int> s;
    bool vis[n];

    for (int i = 0; i < n; i++) {
        vis[i] = false;
        
        if (!ind[i]) {
            q.push(i);
            s.push(i);
            vis[i] = true;
        }
    }

    while (q.size()) {
        int c = q.front();
        q.pop();

        for (int i : v[c]) {
            ind[i]--;

            if (!ind[i] && !vis[i]) {
                q.push(i);
                s.push(i);
                vis[i] = true;
            }
        }
    }

    if (s.size() != n) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        while(s.size()) {
            cout << s.top() + 1 << ' ';
            s.pop();
        }

        cout << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        vector<int> init;
        v[i] = init;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        v[b].push_back(a);
        indegree[a]++;
    }

    topSort(v, indegree, n);
}