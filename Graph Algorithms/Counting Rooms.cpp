#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int N = 1e3+5;

int n, m;
bool used[N][N];

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny])
            dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            used[i][j] = (c == '#');
        }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!used[i][j]) {
                ans++;
                dfs(i, j);
            }

    cout << ans << "\n";
    return 0;
}