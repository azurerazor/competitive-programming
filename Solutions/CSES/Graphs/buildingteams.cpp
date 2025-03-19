#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

vector<int> TwoColor(vector<vector<int>>& graph) {
	int n = sz(graph);
	vector<int> col(n, -1);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (col[i] == -1) q.push(i), col[i] = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto v : graph[u]) {
				if (col[v] == col[u]) return {};
				if (col[v] == -1) {
					col[v] = !col[u]; // inverts color
					q.push(v);
				}
			}
		}
	}
	return col;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> col = TwoColor(graph);

    if (col.empty()) cout << "IMPOSSIBLE\n";
    else for (auto v : col) cout << v+1 << ' ';
    return 0;
}