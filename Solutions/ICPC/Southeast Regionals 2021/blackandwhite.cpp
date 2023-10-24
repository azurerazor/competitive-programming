#include <bits/stdc++.h>
using namespace std;

vector<double> probs(20);
vector<double> memo((1 << 20), -1);
int n;

bool on(int mask, int bit) {
    return ((mask & (1 << bit)) == (1 << bit));
}

double dp(int mask) {
    if (mask == 0) return 0;

    if (memo[mask] != -1) return memo[mask];

    double pb = 1;
    double pw = 1;

    int ons = 0;

    for (int i = 0; i < n; i++) {
        if (on(mask, i)) {
            pb *= probs[i];
            pw *= (1 - probs[i]);
            ons++;
        }
    }

    if (ons <= 2) return 0;

    double ev = 1;
    double tpi = 0;

    for (int i = 0; i < n; i++) {
        if (on(mask, i)) {
            double pi = pb * (1 - probs[i]) / probs[i] + pw * probs[i] / (1 - probs[i]);
            tpi += pi;
            ev += pi*(dp((mask ^ (1 << i))) + 1);
        }
    }
    ev -= tpi;
    ev /= tpi;

    return memo[mask] = ev;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> probs[i];
    }

    int smask = (1 << n) - 1;

    double ans = dp(smask);

    cout << fixed << setprecision(10) << ans << endl;
}
