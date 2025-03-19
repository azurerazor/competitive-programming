#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)size(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

/**
 * @see https://cp-algorithms.com/graph/cutpoints.html
 * @code{.cpp}
       vector<vector<pii>> adj(n);
       rep (i, 0, m) {
           int u, v;
           cin >> u >> v;
           u--, v--;
           adj[u].emplace_back(v, i);
           adj[v].emplace_back(u, i);
       }
       auto [num_bccs, is_cut, bcc_id] = cuts(adj, m);
 * @endcode
 */
struct cuts {
  int num_bccs = 0; /**< number of bi-connected components */
  vector<bool> is_cut; /**< is_cut[node] = 1 iff cut node */
  vector<int> bcc_id; /**< bcc_id[edge id] = id of bcc (which are labeled 0, 1, ..., `num_bccs`-1) */
  /**
   * @param adj undirected graph; possibly with multiple edges; self edges not allowed
   * @param m number of edges
   * @time O(n + m)
   * @space this allocates member vectors which are O(n + m)
   */
  cuts(const vector<vector<pair<int, int>>>& adj, int m) : is_cut((int)(adj).size()), bcc_id(m, -1) {
    int n = (int)(adj).size(), timer = 1;
    vector<int> tin(n), st;
    auto dfs = [&](auto&& self, int u, int p_id) -> int {
      int low = tin[u] = timer++, deg = 0;
      for (auto [v, e_id] : adj[u]) {
        assert(u != v);
        if (e_id == p_id) continue;
        if (!tin[v]) {
          int siz = (int)(st).size();
          st.push_back(e_id);
          int low_ch = self(self, v, e_id);
          if (low_ch >= tin[u]) {
            is_cut[u] = 1;
            for (int i = siz; i < ((int)(st).size()); i++)
              bcc_id[st[i]] = num_bccs;
            st.resize(siz);
            num_bccs++;
          }
          low = min(low, low_ch);
          deg++;
        } else if (tin[v] < tin[u]) {
          st.push_back(e_id);
          low = min(low, tin[v]);
        }
      }
      if (p_id == -1) is_cut[u] = (deg > 1);
      return low;
    };
    for (int i = 0; i < (n); i++)
      if (!tin[i]) dfs(dfs, i, -1);
  }
};
/**
 * @code{.cpp}
       cuts cc(adj, m);
       vector<vi> bvt = block_vertex_tree(adj, cc);
       //to loop over each unique bcc containing a node u:
       for (int bccid : bvt[u]) {
           bccid -= n;
       }
       //to loop over each unique node inside a bcc:
       for (int u : bvt[bccid + n]) {}
 * @endcode
 *
 * [0, n) are original nodes
 * [n, n + num_bccs) are BCC nodes
 *
 * @param adj undirected graph
 * @param cc what's calculated by cuts
 * @returns adjacency list of block vertex tree
 * @time O(n + m)
 * @space besides the O(n + m) sized params, this function allocates and
 * returns `bvt` vector which is O(n)
 */
vector<vector<int>> block_vertex_tree(const vector<vector<pair<int, int>>>& adj, const cuts& cc) {
  int n = (int)(adj).size();
  vector<vector<int>> bvt(n + cc.num_bccs);
  vector<bool> vis(cc.num_bccs);
  for (int i = 0; i < (n); i++) {
    for (auto [_, e_id] : adj[i]) {
      int bccid = cc.bcc_id[e_id];
      if (!vis[bccid]) {
        vis[bccid] = 1;
        bvt[i].push_back(bccid + n);
        bvt[bccid + n].push_back(i);
      }
    }
    for (int bccid : bvt[i]) vis[bccid - n] = 0;
  }
  return bvt;
}

struct BL {
    vector<vi> jmp, gr;
    vi dep;
    int S;
    BL(vector<vi>& g) {
        gr = g;
        S = __lg(sz(g));
        dep = vector<int>(sz(g));
        jmp = vector<vi>(S+1, vi(sz(g)));
        dfs(0);
    }
    void dfs(int u) {
        for (auto v : gr[u]) {
            if (v == jmp[0][u]) continue;
            jmp[0][v] = u;
            dep[v] = dep[u] + 1;
            for (int i = 1; i <= S; i++) {
                jmp[i][v] = jmp[i-1][jmp[i-1][v]];
            }

            dfs(v);
        }
    }
    int jump(int u, int k) {
        for (int i = S; i >= 0; i--) {
            if (k & (1 << i)) u = jmp[i][u];
        }
        return u;
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = jump(u, dep[u]-dep[v]);
        if (u == v) return u;
        
        for (int i = S; i >= 0; i--) {
            if (jmp[i][u] != jmp[i][v]) {
                u = jmp[i][u];
                v = jmp[i][v];
            }
        }

        return jmp[0][u];
    }

    int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u,v)]; }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pii>> gr(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        gr[u].emplace_back(v, i);
        gr[v].emplace_back(u, i);
    }

    cuts c(gr, m);
    vector<vi> bvt = block_vertex_tree(gr, c);
    BL B(bvt);

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; c--;

        if (B.dist(a, b) == B.dist(a, c) + B.dist(b, c)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}