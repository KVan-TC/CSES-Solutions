#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5, oo = 1e9;

int n, S, f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S;

    for (int i = 1; i <= S; i++)
        f[i] = oo;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int s = 0; s <= S - x; s++)
            if (f[s] != oo)
                f[s + x] = min(f[s + x], f[s] + 1);
    }

    cout << (f[S] == oo ? -1 : f[S]) << "\n";
    return 0;
}