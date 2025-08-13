#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;

const int   dx[] = {1, -1, 0, 0},
            dy[] = {0, 0, 1, -1};
const char S[] = {'D', 'U', 'R', 'L'};
const int N = 1e3+5;
const int oo = 1e9;

int n, m, d1[N][N], d2[N][N];
bool esc, used[N][N];
char c[N][N], p[N][N];
pii A, B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    queue<pii> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            if (ch == '#') used[i][j] = true;
            else if (ch == 'M') {
                used[i][j] = true;
                q.push({i, j});
            } else if (ch == 'A')
                A = {i, j};
            c[i][j] = ch;
        }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k]; 
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny]) {
                d1[nx][ny] = d1[x][y] + 1;
                used[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!used[i][j]) d1[i][j] = oo;
            used[i][j] = (c[i][j] == '#');
        }

    used[A.first][A.second] = true;
    q.push(A);
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            int step = d2[x][y];
            string path = "";
            for (int s = step - 1; s >= 0; s--) {
                int k = p[x][y];
                path += S[k];
                x = x - dx[k], y = y - dy[k];
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << step << "\n" << path << "\n";
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && d2[x][y] + 1 < d1[nx][ny]) {
                p[nx][ny] = k;
                d2[nx][ny] = d2[x][y] + 1;
                used[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO\n";
    return 0;
}