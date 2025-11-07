#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int N = 1e3+5;

int n, d[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    queue<pii> q;

    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
