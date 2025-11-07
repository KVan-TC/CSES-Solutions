#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

string a, b;
int f[N], g[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = "#" + a;
    b = "#" + b;

    for (int i = 0; i <= m; i++)
        f[i] = i;

    for (int i = 1; i <= n; i++) {
        g[0] = i;
        for (int j = 1; j <= m; j++)
            g[j] = (a[i] == b[j] ? f[j - 1] : min({f[j], g[j - 1], f[j - 1]}) + 1);
        swap(f, g);
    }

    cout << f[m] << "\n";
    return 0;
}