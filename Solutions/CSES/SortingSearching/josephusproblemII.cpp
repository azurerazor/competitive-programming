#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;

    Tree<int> t;

    for (int i = 0; i < n; i++) {
        t.insert(i+1);
    }

    t.erase(0);

    int idx = k % n;

    for (int i = 0; i < n; i++) {
        int rem = *t.find_by_order(idx);
        cout << rem << ' ';
        t.erase(rem);
        idx += k;
        if (t.size() != 0) idx %= t.size();
    }

    cout << endl;
    return 0;
}