#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool cmp(array<int, 2> a, array<int, 2> b) {
    if (a[0] != b[0]) return (a[0] > b[0]);
    return (a[1] < b[1]);
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid.size();
}

array<int, 2> flood(int x, int y) {
    grid[x][y] = '*';
    array<int, 2> res;
    res[0] = 1;
    res[1] = 0;

    for (int i = 0; i < 4; i++) {
        if (isValid(x+dx[i],y+dy[i]) && grid[x+dx[i]][y+dy[i]] != '.') {
            if (grid[x+dx[i]][y+dy[i]] == '#') {
                array<int, 2> temp = flood(x+dx[i], y+dy[i]);
                res[0] += temp[0]; res[1] += temp[1];
            }
        } else {
            res[1]++;
        }
    }

    return res;
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    int n;
    fin >> n;

    grid = vector<string>(n);

    for (int i = 0; i < n; i++) fin >> grid[i];

    vector<array<int, 2>> blobs;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                blobs.push_back(flood(i,j));
            }
        }
    }

    sort(blobs.begin(), blobs.end(), cmp);

    fout << blobs[0][0] << ' ' << blobs[0][1] << '\n';
}