#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
struct scc_info {
    int num_sccs;
    vector<int> scc_id;
};
 
scc_info SCC(const vector<vector<int>>& adj) {
    int n = adj.size(), time = 1, num_sccs = 0;
    vector<int> tin(n), scc_id(n, -1), node_stack;
    node_stack.reserve(n);
    auto dfs = [&](auto&& self, int u) -> int {
        int low = tin[u] = time++;
        node_stack.push_back(u);
        for (auto v : adj[u]) {
            if (scc_id[v] < 0) {
                low = min(low, tin[v] ? tin[v] : self(self, v));
            }
        }
        if (tin[u] == low) {
            while(1) {
                int node = node_stack.back();
                node_stack.pop_back();
                scc_id[node] = num_sccs;
                if (node == u) break;
            }
            num_sccs++;
        }
        return low;
    };
    for (int i = 0; i < n; i++) {
        if (!tin[i]) {
            dfs(dfs, i);
        }
    }
    return {num_sccs, scc_id};
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> g(n);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
 
    auto [tot, id] = SCC(g);
 
    cout << tot << '\n';
    for (auto i : id) cout << (i+1) << ' ';
    cout << endl;
}
