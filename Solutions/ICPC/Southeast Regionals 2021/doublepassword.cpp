#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;
    int c = 1;

    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            c *= 2;
        }
    }

    cout << c << endl;
}