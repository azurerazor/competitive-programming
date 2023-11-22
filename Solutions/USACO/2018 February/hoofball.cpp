// overcomplicating the problem because i am too lazy to figure out the actual sol we love to see it

#include <bits/stdc++.h>
using namespace std;

vector<bool> passed;
vector<int> graph;

void dfs(int a, int p) {
    passed[a] = false;
    if (graph[a] != p) dfs(graph[a], a);
}

int main() {
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    int n;
    fin >> n;

    vector<int> pos(n);
    
    for (int i = 0; i < n; i++) fin >> pos[i];
    sort(pos.begin(), pos.end());

    graph = vector<int>(n);
    if (n > 1) {
        graph[0] = 1;
        graph[n-1] = n-2;
    }

    for (int i = 1; i < n-1; i++) {
        if (pos[i+1] - pos[i] < pos[i] - pos[i-1]) graph[i] = i+1;
        else graph[i] = i-1;
    }

    passed = vector<bool>(n, true);

    for (int i = 0; i < n; i++) {
        if (passed[i]) {
            dfs(i,i);
            passed[i] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (passed[i]) {
            ans++;
        }
    }

    fout << ans << '\n';
    return 0;
}
