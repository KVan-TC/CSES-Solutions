#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500 * 501 / 4 + 1;
const int M = 1e9 + 7;
const int inv2 = (M + 1) / 2;

int n;
ll f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    if (n % 4 != 0 && n % 4 != 3) return cout << "0\n", 0;

    int S = n * (n + 1) / 4;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i * (i + 1) / 2, S); j >= i; j--)
            f[j] = (f[j] + f[j - i]) % M;

    cout << f[S] * inv2 % M << "\n";
    return 0;
}
