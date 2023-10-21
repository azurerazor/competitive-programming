#include <bits/stdc++.h>
using namespace std;

struct DSU {
    // why does it work when I steal it but not when I try to actually code it :(
	vector<int> s;
    int numGroups;
    int maxSize;
	DSU(int n): s(n, -1), numGroups(n), maxSize(1) {}
	int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }

	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (s[a] > s[b]) swap(a, b);
		s[a] += s[b], s[b] = a;
        numGroups--;
        maxSize = max(maxSize, -s[a]);
		return true;
	}

	int size(int i) { return -s[find(i)]; }
	bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU d = DSU(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        d.join(a, b);
        cout << d.numGroups << " " << d.maxSize << endl;
    }

    return 0;
}