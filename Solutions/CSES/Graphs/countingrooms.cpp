#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void fill(int x, int y) {
    grid[x][y] = '#';

    for (int i = 0; i < 4; i++) {
        if (isValid(x + dx[i], y + dy[i]) && grid[x + dx[i]][y + dy[i]] == '.') {
            fill(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    cin >> n >> m;

    grid = vector<string>(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int regions = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                regions++;
                fill(i, j);
            }
        }
    }

    cout << regions << endl;
}