#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e16;

int n, m;

void floydWarshall(vector<vector<ll>>& graph) {
    for (int p = 0; p < n; p++) {
        for (int s = 0; s < n; s++) {
            for (int d = 0; d < n; d++) {
                graph[s][d] = min(graph[s][d], graph[s][p] + graph[p][d]);
            }
        }
    }
}

int main() {
    int q;
    cin >> n >> m >> q;

    vector<vector<ll>> graph(n, vector<ll>(n, inf));

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a][b] = min(graph[a][b], w);
        graph[b][a] = graph[a][b];
    }

    floydWarshall(graph);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        cout << ((graph[a][b] >= inf) ? -1 : graph[a][b]) << endl;
    }

    return 0;
}