#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

pair<bool, vector<int>> twoColor() {
    vector<int> colors(n, -1);
    queue<int> q;
    int visNodes = 0;

    bool colorable = true;

    q.push(0);
    colors[0] = 0;

    while (visNodes < n) {
        while (q.size()) {
            int c = q.front();
            q.pop();
            visNodes++;

            for (auto v : graph[c]) {
                if (colors[v] == -1) {
                    colors[v] = !colors[c];
                    q.push(v);
                } else if (colors[v] == colors[c]) {
                    colorable = false;
                    break;
                }
            }

            if (!colorable) break;
        }

        if (!colorable) break;

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                q.push(i);
                colors[i] = 0;
                break;
            }
        }
    }

    return {colorable, colors};
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

    pair<bool, vector<int>> colors = twoColor();

    if (colors.first) {
        for (int i = 0; i < n; i++) {
            cout << colors.second[i] + 1 << " ";
        }

        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
