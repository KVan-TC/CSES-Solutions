#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6+5, M = 1e9+7;

int T;
ll f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    f[1] = 2;
    f[2] = 8;

    for (int i = 3; i <= N; i++)
        f[i] = ((6 * f[i - 1] - 7 * f[i - 2]) % M + M) % M;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int n; cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}