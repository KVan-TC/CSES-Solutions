#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, W, v[1005], w[1005], f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> W;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[W] << "\n";
    return 0;
}