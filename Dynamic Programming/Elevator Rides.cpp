#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 20;
const int oo = 2e9;

int n;
pii f[1<<N];
ll X, w[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> X;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    f[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        f[mask] = {oo, 0};
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) {
                pii nxt = f[mask ^ (1 << i)];
                if (nxt.second + w[i] <= X)
                    nxt.second += w[i];
                else {
                    nxt.first++;
                    nxt.second = w[i];
                }
                f[mask] = min(f[mask], nxt);
            }
    }

    cout << f[(1 << n) - 1].first << "\n";
    return 0;
}
