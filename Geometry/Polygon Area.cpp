#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3+5;

int n;
ll x[N], y[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0]; y[n] = y[0];

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += x[i] * y[i + 1], ans -= y[i] * x[i + 1];

    cout << abs(ans) << "\n";

    return 0;
}
