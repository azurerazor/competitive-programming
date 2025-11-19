/*
* Source: own
* Desc: aho-corasick that is in topological order. Used for multi-pattern matching.
* Test: https://cses.fi/problemset/task/2102/
*/

#define ALPHA 26
#define FL 'a'
 
struct node {
    array<int, ALPHA> nxt;
    int prv, link, len; vi ids;
    node(int p, int k, int l) : prv(p), link(k), len(l) {
        fill(all(nxt), 0); }
};

vector<node> build(vector<string>& s) {
    vector<node> aho{{0, 0, 0}};
    aho[0].ids = vi(sz(s));
    iota(all(aho[0].ids), 0);

    for (int u = 0; u < sz(aho); u++) {
        aho[u].nxt = aho[aho[u].link].nxt;
        for (int i = 0; i < sz(aho[u].ids); i++) {
            int c = aho[u].ids[i], L = aho[u].len;
            if (L < sz(s[c])) {
                int ch = s[c][L] - FL;
                if (aho[aho[u].nxt[ch]].len < L+1) {
                    int j = sz(aho);
                    aho.emplace_back(u, aho[aho[u].link].nxt[ch], L+1);
                    aho[u].nxt[ch] = j;
                }
                swap(aho[u].ids[i--], aho[u].ids.back());
                aho[u].ids.pop_back();
                aho[aho[u].nxt[ch]].ids.push_back(c);
            }
        }
    }

    return aho;
