#include <bits/stdc++.h>
using namespace std;
 
void gray(int curr, string& s) {
    if (curr >= s.length()) {
        cout << s << '\n';
        return;
    }
    gray(curr+1, s);
    if (s[curr] == '0') s[curr] = '1';
    else s[curr] = '0';
    gray(curr+1, s);
}
 
int main() {
    int n; cin >> n;
 
    string bit;
    for (int i = 0; i < n; i++) bit += '0';
    gray(0, bit);
}