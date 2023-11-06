#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll sum = 0;

    vector<int> apples(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        sum += apples[i];
    }

    ll mini = 1e16;

    // the ordering of the sets does not matter,
    // so you only have to check half of the states
    // therefore you only have to go up to 2^(n-1) rather than 2^n
    for (int i = 0; i < (1 << (n-1)); i++) {
        ll curr = 0;
        for (int j = 0; j < n-1; j++) {
            if (i & (1<<j)) curr += apples[j];
        }
        mini = min(mini, abs(sum - 2*curr));
    }

    cout << mini << endl;
    return 0;
}
