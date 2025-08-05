#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5+5, M = 1e9+7;

int n, m, a[N];
ll f[105], g[105];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0])
        f[a[0]] = 1;
    else
        for (int i = 1; i <= m; i++)
            f[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) g[j] = f[j], f[j] = 0;

        int x = a[i];
        if (x)
            f[x] = g[x - 1] + g[x] + g[x + 1], f[x] %= M;
        else {
            for (int i = 1; i < m; i++)
                f[i] = g[i - 1] + g[i] + g[i + 1], f[i] %= M;
            f[m] = g[m - 1] + g[m], f[m] %= M;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans += f[i], ans %= M;

    cout << ans << "\n";
    return 0;
}