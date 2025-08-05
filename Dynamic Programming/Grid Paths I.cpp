#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3+5, M = 1e9 + 7;

int n, f[2][N];
char c[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    f[1][1] = (c[1][1] == '.');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            f[i % 2][j] = 0;
            if (c[i][j] == '*') continue;
            if (c[i][j - 1] == '.')
                f[i % 2][j] += f[i % 2][j - 1];
            if (c[i - 1][j] == '.')
                f[i % 2][j] += f[(i - 1) % 2][j];
            f[i % 2][j] %= M;
        }

    cout << f[n % 2][n] << "\n";
    return 0;
}