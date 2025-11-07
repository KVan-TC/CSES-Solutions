#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, m, a[N], b[N], f[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);

    int l = f[n][m];
    cout << l << "\n";
    vector<int> v;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j] && f[i][j] == l) {
                v.push_back(a[i]);
                l--;
                break;
            }
    }
    reverse(v.begin(), v.end());
    for (int x : v)
        cout << x << " ";
    return 0;
}
