#include <bits/stdc++.h>
using namespace std;

vector<string> sheet;
vector<vector<int>> grid;
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >=0 && y >= 0 && x < n && y < m;
}

int bfs(queue<pair<int, int>>& q) {
    int ans = 1;
    
    while (q.size()) {
        pair<int, int> c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (isValid(c.first + dx[i], c.second + dy[i]) && grid[c.first + dx[i]][c.second + dy[i]] == -1 && sheet[c.first + dx[i]][c.second + dy[i]] == 'X') {
                grid[c.first + dx[i]][c.second + dy[i]] = grid[c.first][c.second] + 1;
                ans = grid[c.first][c.second] + 1;
                q.push({c.first + dx[i], c.second + dy[i]});
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    sheet = vector<string>(n);
    grid = vector<vector<int>>(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        cin >> sheet[i];
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sheet[i][j] == 'X') {
                int numAdj = 0;

                for (int k = 0; k < 4; k++) {
                    if (isValid(i + dx[k], j + dy[k]) && sheet[i + dx[k]][j + dy[k]] == 'X') {
                        numAdj++;
                    }
                }

                if (numAdj != 4) {
                    q.push({i, j});
                    grid[i][j] = 1;
                }
            }
        }
    }

    cout << bfs(q) << endl;
}