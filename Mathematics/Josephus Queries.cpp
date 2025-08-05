#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int T;

int sol(int n, int k) {
    if (2 * k <= n) return 2 * k;
    if (n & 1)
        return sol(n / 2, k - n / 2 - 1) * 2 + 1;
    return sol(n / 2, k - n / 2) * 2 - 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while (T--) {
        int n, k; cin >> n >> k;

        cout << sol(n, k) << "\n";
    }
    return 0;
}