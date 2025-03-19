#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;
    if (a1 < b1) return 1;
    if (a1 == b1 && a2 > b2) return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    Tree<pair<int, int>> l, r;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b, i});
        r.insert({b, i});
    }

    vector<int> in(n), out(n);
    sort(all(v), cmp);

    for (int i = 0; i < n; i++) {
        auto [a, b, q] = v[i];
        r.erase({b, q});
        if (i) {
            auto c = (l.lower_bound({b, 0}));
            if (c != l.end()) in[q] += sz(l) - (int)l.order_of_key(*c);
        }
        if (i < n-1) {
            auto c = r.lower_bound({b+1, 0});
            if (c != r.end()) out[q] += r.order_of_key(*c);
            else out[q] += sz(r);
        }
        l.insert({b, q});
    }

    for (auto v : out) cout << v << ' ';
    cout << '\n';
    for (auto v : in) cout << v << ' ';
    cout << '\n';

    return 0;
}