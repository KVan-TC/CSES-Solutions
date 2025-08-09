#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 500;

int a, b, F[N+1][N+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for (int a = 1; a <= N; a++) {
        F[a][1] = F[1][a] = a - 1;
        for (int b = 2; b < a; b++) {
            int *f = F[b], *g = F[a];
            int p = a * b;
            for (int c = 1; c <= a / 2; c++)
                p = min(p, f[c] + f[a - c] + 1);
            for (int c = 1; c <= b / 2; c++)
                p = min(p, g[c] + g[b - c] + 1);
            f[a] = g[b] = p;
        }
    }

    cin >> a >> b;
    cout << F[a][b] << "\n";
    return 0;
}
