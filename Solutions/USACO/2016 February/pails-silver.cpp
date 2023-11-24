#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int x, y, k, m;
    fin >> x >> y >> k >> m;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(x+1, vector<int>(y+1, -1));
    q.push({0, 0});
    dist[0][0] = 0;

    int err = 2e9;

    while (q.size()) {
        auto [cx, cy] = q.front();
        q.pop();

        err = min(err, abs(m - cx - cy));
        if(dist[cx][cy] == k) continue;

        // casework hell ?
        if (dist[x][cy] == -1) {
            q.push({x,cy});
            dist[x][cy] = dist[cx][cy] + 1;
        }
        if (dist[cx][y] == -1) {
            q.push({cx,y});
            dist[cx][y] = dist[cx][cy] + 1;
        }
        if (dist[0][cy] == -1) {
            q.push({0,cy});
            dist[0][cy] = dist[cx][cy] + 1;
        }
        if (dist[cx][0] == -1) {
            q.push({cx,0});
            dist[cx][0] = dist[cx][cy] + 1;
        }
        if (dist[min(cx+cy, x)][max(0, cy - (x - cx))] == -1) {
            q.push({min(cx+cy, x),max(0, cy - (x - cx))});
            dist[min(cx+cy, x)][max(0, cy - (x - cx))] = dist[cx][cy] + 1;
        }
        if (dist[max(0, cx - (y - cy))][min(cx+cy, y)] == -1) {
            q.push({max(0, cx - (y - cy)),min(cx+cy, y)});
            dist[max(0, cx - (y - cy))][min(cx+cy, y)] = dist[cx][cy] + 1;
        }
    }

    fout << err << '\n';
    return 0;
}
