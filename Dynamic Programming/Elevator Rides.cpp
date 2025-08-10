#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;

const int N = 20;
const int oo = 2e9;

int n;
pii f[1<<N];
ll X, w[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> X;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    f[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        f[mask] = {oo, 0};
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) {
                pii nxt = f[mask ^ (1 << i)];
                if (nxt.se + w[i] <= X)
                    nxt.se += w[i];
                else {
                    nxt.fi++;
                    nxt.se = w[i];
                }
                f[mask] = min(f[mask], nxt);
            }
    }

    cout << f[(1 << n) - 1].fi << "\n";
    return 0;
}
