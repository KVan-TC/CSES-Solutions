#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

using ll = long long;

const int N = 2e5 + 5;

int n, x, len, f[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (cin >> n; cin >> x; ) {
        int it = lower_bound(f, f + len, x) - f;
        if (it == len)
            len++, f[it] = x;
        else
            f[it] = min(f[it], x);
    }
    cout << len << "\n";
    return 0;
}
