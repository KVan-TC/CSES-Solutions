#include <bits/stdc++.h>
using namespace std;

const int N = 7;

int ans;
string S;
bool used[N+2][N+2];

void dfs(int x, int y, int step) {
    if (used[x][y]) return;
    
    if (step == N * N - 1 || (x == N && y == 1)) {
        ans += (step == N * N - 1 && x == N && y == 1);
        return;
    }

    bool D = used[x + 1][y], U = used[x - 1][y], R = used[x][y + 1], L = used[x][y - 1];
    if ((D && U && !R && !L) || (!D && !U && R && L)) return;

    char c = S[step]; 
    used[x][y] = 1;
    if (c == '?' || c == 'D') dfs(x + 1, y, step + 1);
    if (c == '?' || c == 'U') dfs(x - 1, y, step + 1);
    if (c == '?' || c == 'R') dfs(x, y + 1, step + 1);
    if (c == '?' || c == 'L') dfs(x, y - 1, step + 1);
    used[x][y] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S;

    for (int i = 0; i < N + 2; i++) {
        used[0][i] = used[N + 1][i] = 1;
        used[i][0] = used[i][N + 1] = 1;
    }
    dfs(1, 1, 0);

    cout << ans << "\n";
    return 0;
}
