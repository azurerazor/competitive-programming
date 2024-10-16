#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// KACTL Aho
struct AhoCorasick {
	enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
        int dep = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) {
                int tmp = n;
                n = m = sz(N);
                N.emplace_back(-1);
                N.back().dep = N[tmp].dep + 1;
            }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    freopen("censor.in", "r+", stdin);
    freopen("censor.out", "w+", stdout);

    string s;
    cin >> s;

    int n;
    cin >> n;
    vector<string> pat(n);

    for (int i = 0; i < n; i++) cin >> pat[i];

    AhoCorasick A(pat);

    vector<int> st;
    vector<int> state;
    vector<bool> deleted(sz(s));

    int c = 0;
    for (int i = 0; i < sz(s); i++) {
        c = A.N[c].next[s[i] - 'a'];
        state.push_back(c);
        st.push_back(i);
        if (A.N[c].nmatches > 0 && sz(st) >= A.N[c].dep) {
            for (int i = 0; i < A.N[c].dep; i++) {
                int u = st.back();
                st.pop_back();
                deleted[u] = 1;
            }
            if (sz(st)) c = state[st.back()];
            else c = 0;
        }
    }

    for (int i = 0; i < sz(s); i++) {
        if (!deleted[i]) cout << s[i];
    }

    cout << '\n';
    return 0;
}
