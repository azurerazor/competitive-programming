#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int players[1 << n];

    for (int i = 0; i < (1 << n); i++) {
        cin >> players[i];
    }

    sort(players, players + (1 << n));

    int pointer;
    int cgames = 0;

    for (int i = 0; i < n; i++) {
        pointer = (1 << n) - (1 << i) - 1;

        for (int j = (1 << n) - 1; j > (1 << n) - (1 << i) - 1; j--) {
            if (players[j] - players[pointer] <= k) {
                pointer--;
                cgames++;
            }
        }
    }

    cout << cgames << endl;
}