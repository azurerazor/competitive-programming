#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    int a, b, x, y;
    fin >> a >> b >> x >> y;
    fout << min(abs(b-a), min(abs(x-a) + abs(y-b), abs(x-b) + abs(y-a))) << '\n';
    return 0;
}