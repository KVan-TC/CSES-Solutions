#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e3+5;

int n, x[N];
ll S, f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        f[i] = x[i];
        S += x[i];
    }

    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            f[l] = max(x[l] - f[l + 1], x[r] - f[l]);
        }

    cout << (S + f[0]) / 2 << "\n";
    return 0;
}
