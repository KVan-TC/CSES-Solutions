#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    int len = 0;
    while (n--) {
        int x; cin >> x;
        int it = lower_bound(f, f + len, x) - f;
        if (it == len)
            len++, f[it] = x;
        else
            f[it] = min(f[it], x);
    }
    cout << len << "\n";
    return 0;
}
