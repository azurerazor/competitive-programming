#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    while(1) {
        cout << n << ' ';
        if (n == 1) break;
        n = ((n&1) ? 3*n+1 : (n>>1));
    }
    cout << '\n';

    return 0;
}