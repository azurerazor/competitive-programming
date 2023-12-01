#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

namespace std {
    void swap(Tree<int> &a, Tree<int> &b) { a.swap(b); }
} 

Tree<int> cows[100005];
vector<int> skill;
vector<int> ans;

void stl(int u, int p, vector<vector<int>>& g) {
    for (auto v : g[u]) {
        if (v == p) continue;
        stl(v, u, g);

        if (cows[u].size() < cows[v].size()) std::swap(cows[u], cows[v]);
        for (auto& k : cows[v]) cows[u].insert(k);
    }

    ans[u] = cows[u].size() - cows[u].order_of_key(skill[u]) - 1;
}

int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    int n;
    fin >> n;

    skill = vector<int>(n);
    ans = vector<int>(n);

    for (int i = 0; i < n; i++) {
        fin >> skill[i];
        cows[i].insert(skill[i]);
    }

    vector<vector<int>> graph(n);

    for (int i = 1; i < n; i++) {
        int v; fin >> v; v--;
        graph[v].push_back(i);
        graph[i].push_back(v);
    }

    stl(0, 0, graph);

    for (auto v : ans) fout << v << '\n';
    return 0;
}