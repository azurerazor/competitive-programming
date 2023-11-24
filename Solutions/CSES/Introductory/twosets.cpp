#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
 
    vector<int> set1;
    vector<int> set2;
 
    if (n % 4 == 3) {
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);
 
        for (int i = 4; i <= n; i++) {
            if ((i+1) % 4 > 1) set1.push_back(i);
            else set2.push_back(i);
        }
 
        cout << "YES\n";
        cout << set1.size() << '\n';
        for (int i = 0; i < set1.size(); i++) cout << set1[i] << ' ';
        cout << '\n';
        cout << set2.size() << '\n';
        for (int i = 0; i < set2.size(); i++) cout << set2[i] << ' ';
        cout << '\n';
    } else if (n % 4 == 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 4 > 1) set1.push_back(i);
            else set2.push_back(i);
        }
 
        cout << "YES\n";
        cout << set1.size() << '\n';
        for (int i = 0; i < set1.size(); i++) cout << set1[i] << ' ';
        cout << '\n';
        cout << set2.size() << '\n';
        for (int i = 0; i < set2.size(); i++) cout << set2[i] << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}