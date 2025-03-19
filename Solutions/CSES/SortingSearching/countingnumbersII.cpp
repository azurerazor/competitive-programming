#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<int> idx(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        idx[arr[i]] = i;
    }

    int ans = 1;

    for (int i = 1; i < n; i++) ans += (idx[i-1] > idx[i]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        int n1 = arr[a], n2 = arr[b];
        if (abs(n1-n2) == 1) {
            int mn, mx, mni, mxi;
            if (n1 - n2 > 0) {
                ans--;
                mn = n2, mx = n1;
                mni = b, mxi = a;
            } else {
                ans++;
                mn = n1, mx = n2;
                mni = a, mxi = b;
            }
            if (mn > 0 && idx[mn-1] < mni && idx[mn-1] > mxi) ans++;
            else if (mn > 0 && idx[mn-1] > mni && idx[mn-1] < mxi) ans--;
            if (mx < n-1 && idx[mx+1] < mxi && idx[mx+1] > mni) ans--;
            else if (mx < n-1 && idx[mx+1] > mxi && idx[mx+1] < mni) ans++;
        } else if (a != b) {
            for (int j = n1; j == n2 || j == n1; j += (n2-n1)) {
                if (j > 0 && idx[j-1] < a && idx[j-1] > b) ans++;
                else if (j > 0 && idx[j-1] > a && idx[j-1] < b) ans--;
                if (j < n-1 && idx[j+1] < a && idx[j+1] > b) ans--;
                else if (j < n-1 && idx[j+1] > a && idx[j+1] < b) ans++;
                swap(a, b);
            }
        }
        cout << ans << '\n';
        swap(arr[a], arr[b]);
        swap(idx[n1], idx[n2]);
    }
}