#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 10;
const int M = 1e9 + 7;

int n, m, f[1<<N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    f[0] = 1;
    for (; m; m--) {
        reverse(f, f + (1 << n));
        for (int i = 0; i < n - 1; i++)
            for (int mask = 0; mask < (1 << n); mask++)
                if (!(mask & (3 << i))) 
                    f[mask] = (f[mask] + f[mask | (3 << i)]) % M;
    }

    cout << f[0] << "\n";
    return 0;
}
