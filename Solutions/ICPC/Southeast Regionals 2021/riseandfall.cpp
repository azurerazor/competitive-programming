#include <bits/stdc++.h>
using namespace std;

int main() {
    const int M = 48;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;
    cin >> c;

    while (c--) {
        string s;
        cin >> s;

        int ind = -1;
        char lol = s[0];

        for (int i = 1; i < s.length(); i++) {
            char b = s[i];

            if (b < lol) {
                ind = i;
                break;
            }

            lol = b;
        }

        bool flag = false;

        if (ind != -1) {
            lol = s[ind];

            for (int i = ind + 1; i < s.length(); i++) {
                char b = s[i];

                if (lol < b) {
                    s[i] = lol;
                    flag = true;
                }

                if (lol > b && flag) {
                    s[i] = lol;
                }

                lol = s[i];
            }
        }

        cout << s << '\n';
    }

    return 0;
}