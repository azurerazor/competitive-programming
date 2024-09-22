#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};
 
struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
 
    FT2 ft = FT2(n + 1);
    vector<string> grid(n);
    vector<vector<int>> ps(n+1, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + (grid[i][j] == '*');
        }
    }
 
    vector<vector<int>> queries;
 
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            queries.push_back({x-1, y-1});
            ft.fakeUpdate(x-1, y-1);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            queries.push_back({x1-1, y1-1, x2, y2});
        }
    }
 
    ft.init();
 
    for (auto& v : queries) {
        if (v.size() == 4) {
            int ans = ft.query(v[2], v[3]) - ft.query(v[2], v[1]) - ft.query(v[0], v[3]) + ft.query(v[0], v[1]);
            ans += ps[v[2]][v[3]] - ps[v[2]][v[1]] - ps[v[0]][v[3]] + ps[v[0]][v[1]];
            cout << ans << '\n';
        } else {
            int x = v[0], y = v[1];
            if (grid[x][y] == '*') {
                ft.update(x, y, -1);
                grid[x][y] = '.';
            } else {
                ft.update(x, y, 1);
                grid[x][y] = '*';
            }
        }
    }
 
    return 0;
}