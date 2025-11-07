#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+5, M = 1e9 + 7;

int n, S, a[105], f[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> S;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    f[0] = 1;
    for (int s = 1; s <= S; s++) {
        ll t = 0;
        for (int i = 0; i < n; i++)
            if (s >= a[i]) t += f[s - a[i]];
        f[s] = t % M;
    }

    cout << f[S] << "\n";
    return 0;
}