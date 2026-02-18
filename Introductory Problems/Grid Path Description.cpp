#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int N = 7;

string s;
int ans;
bool used[N+5][N+5];

void dfs(int i, int x, int y) {
    if (used[x][y]) return;

    if (i == N * N || (x == N && y == 1)) {
        ans += (i == N * N && x == N && y == 1);
        return;
    }

    bool D = used[x + 1][y], U = used[x - 1][y], R = used[x][y + 1], L = used[x][y - 1];
    if ((D && U && !L && !R) || (!D && !U && L && R)) return;

    char c = s[i];
    used[x][y] = 1;
    if (c == '?' || c == 'D') dfs(i + 1, x + 1, y);
    if (c == '?' || c == 'U') dfs(i + 1, x - 1, y);
    if (c == '?' || c == 'R') dfs(i + 1, x, y + 1);
    if (c == '?' || c == 'L') dfs(i + 1, x, y - 1);
    used[x][y] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> s; 
    s = '#' + s;

    for (int i = 0; i < N + 1; i++)
        used[0][i] = used[N + 1][i] = used[i][0] = used[i][N + 1] = 1;
    
    dfs(1, 1, 1);
    cout << ans << "\n";

    return 0;
}
