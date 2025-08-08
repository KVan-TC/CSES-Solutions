#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, p[25], ans;
int k;

void sol(int i, ll g, ll s) {
    if (i == k) ans += g * s;
    else {
        sol(i + 1, g, s);
        sol(i + 1, g / p[i], -s);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> p[i];

    sol(0, n, 1);
    cout << n - ans << "\n";
    return 0;
}
