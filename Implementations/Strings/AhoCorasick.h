#define ALPHA 26
#define FL 'A'

struct node {
    int nxt[ALPHA];
    int prv=0, link=0, len=0;
    char c;
    vi ids;
    node(int p, int k, int l, char c): 
        prv(p), link(k), len(l), c(c) {
        memset(nxt, 0, sizeof(nxt));
    }
};

vector<node> build(vector<string>& s) {
    vector<node> aho;
    aho.emplace_back(0, 0, 0, 0);
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < sz(s); i++) {
        q.emplace(0, i, 0);
    }
    while (sz(q)) {
        auto [p, i, n] = q.front(); q.pop();
        char cc = s[i][p] - FL;
        if (aho[n].nxt[cc] < aho[n].len+1) {
            int j = sz(aho);
            aho.emplace_back(n, aho[aho[n].link].nxt[cc],
                 aho[n].len+1, cc);
            aho[n].nxt[cc] = j;
            for (int k = 0; k < ALPHA; k++) {
                aho[j].nxt[k] = aho[aho[j].link].nxt[k];
            }
        }
        int x = aho[n].nxt[cc];
        if (p+1==sz(s[i])) aho[x].ids.push_back(i);
        else q.emplace(p+1, i, x);
    }

    return aho;
}
