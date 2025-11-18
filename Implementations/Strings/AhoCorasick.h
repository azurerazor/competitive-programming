/*
* Source: own
* Desc: aho-corasick that is in topological order. Used for multi-pattern matching.
* Test: https://cses.fi/problemset/task/2102/
*/

#define ALPHA 26
#define FL 'a'
 
struct node {
    int nxt[ALPHA];
    int prv=0, link=0, len=0;
    vi ids;
    node(int p, int k, int l): 
        prv(p), link(k), len(l) {
        memset(nxt, 0, sizeof(nxt));
    }
};
 
vector<node> build(vector<string>& s) {
    vector<node> aho;
    aho.emplace_back(0, 0, 0);
    aho[0].ids = vi(sz(s));
    iota(all(aho[0].ids), 0);

    for (int u = 0; u < sz(aho); u++) {
        for (int i = 0; i < ALPHA; i++)
            aho[u].nxt[i] = aho[aho[u].link].nxt[i];
        for (int i = 0; i < sz(aho[u].ids); i++) {
            int c = aho[u].ids[i];
            if (aho[u].len < sz(s[c])) {
                int ch = s[c][aho[u].len] - FL;
                if (aho[aho[u].nxt[ch]].len < aho[u].len+1) {
                    int j = sz(aho);
                    aho.emplace_back(u, aho[aho[u].link].nxt[ch], aho[u].len+1);
                    aho[u].nxt[ch] = j;
                }
                swap(aho[u].ids[i], aho[u].ids[sz(aho[u].ids) - 1]);
                aho[u].ids.pop_back();
                i--;
                aho[aho[u].nxt[ch]].ids.push_back(c);
            }
        }
    }
 
    return aho;
}
