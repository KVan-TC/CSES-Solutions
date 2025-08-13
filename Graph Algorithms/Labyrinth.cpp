#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
const int   dx[] = {-1, 1, 0, 0},
            dy[] = {0, 0, -1, 1};
const char C[] = {'U', 'D', 'L', 'R'};
const int N = 1e3+5;
 
int n, m;
bool used[N][N];
char trace[N][N];
pii A, B, par[N][N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            trace[i][j] = c;
            if (c == 'A') A = {i, j};
            if (c == 'B') B = {i, j};
        }
 
    queue<pii> q;
    used[A.first][A.second] = 1;
    q.push(A);
    par[A.first][A.second] = {-1, -1};
 
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
 
        if (make_pair(x, y) == B) {
            int u = x, v = y;
            string path = "";
            while (par[u][v].first != -1) {
                path += trace[u][v];
                tie(u, v) = par[u][v];
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << path << "\n";
            return 0;
        }
 
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && (trace[nx][ny] == '.' || make_pair(nx, ny) == B)) {
                par[nx][ny] = {x, y};
                trace[nx][ny] = C[k];
                q.push({nx, ny});
            }
        }
    }
 
    cout << "NO\n";
    return 0;
}
