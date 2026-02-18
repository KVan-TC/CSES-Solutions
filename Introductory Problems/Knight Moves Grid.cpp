#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int N = 1e3+5;
const int dx[] = {1, 2,  2,  1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1,  1,  2};

int n, d[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;

    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1) {
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
