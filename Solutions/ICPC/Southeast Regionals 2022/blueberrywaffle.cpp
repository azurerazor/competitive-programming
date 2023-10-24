#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double r, f;
    cin >> r >> f;

    int turns = (int) round(f / r);

    cout << ((turns % 2 == 0) ? "up" : "down") << endl;
}