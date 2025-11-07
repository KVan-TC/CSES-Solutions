#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5, M = 1e9 + 7;

int n, S, f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S;

    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int s = x; s <= S; s++)
            f[s] += f[s - x], f[s] %= M;
    }

    cout << f[S] << "\n";
    return 0;
}