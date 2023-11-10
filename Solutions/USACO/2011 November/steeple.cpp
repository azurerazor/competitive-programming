// can't confirm this 100% works since original version is closed, but a modified version of this code worked with slightly modified input

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

struct hLine {
    int x1, x2, y;
    hLine(int a, int b, int c) {
        x1 = min(a,b); x2 = max(a,b); y = c;
    }
};

struct vLine {
    int x, y1, y2;
    vLine(int a, int b, int c) {
        x = a; y1 = min(b,c); y2 = max(b, c);
    }
    bool intersec(hLine& h) {
        return (h.x1 <= x && x <= h.x2 && y1 <= h.y && h.y <= y2 );
    }
};



int main() {
    ifstream fin("steeple.in");
    ofstream fout("steeple.out");

    ios_base::sync_with_stdio(0);
    fin.tie(0);

    int o; fin >> o;

    vector<hLine> hl;
    vector<vLine> vl;

    for (int i = 0; i < o; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        if (abs(x1-x2)) {
            hLine h = hLine(x1, x2, y1);
            hl.push_back(h);
        } else {
            vLine v = vLine(x1, y1, y2);
            vl.push_back(v);
        }
    }

    int N = 2 + sz(hl) + sz(vl);

    Dinic d = Dinic(N);

    for (int i = 0; i < sz(hl); i++) {
        d.addEdge(0, 2 + i, 1);
    }

    for (int i = 0; i < sz(vl); i++) {
        d.addEdge(2 + sz(hl) + i, 1, 1);
    }

    for (int i = 0; i < sz(hl); i++) {
        for (int j = 0; j < sz(vl); j++) {
            if (vl[j].intersec(hl[i])) {
                d.addEdge(2 + i, 2 + sz(hl) + j, 1);
            }
        }
    }

    fout << (N - d.calc(0, 1) - 2) << '\n';
    return 0;
}
