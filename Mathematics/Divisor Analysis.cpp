#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5, M = 1e9 + 7;

int n;
ll p[N], k[N];

ll s(ll n) {
    return n * (n + 1) / 2;
}

ll pw(ll x, ll n, ll q) {
    ll a = 1;
    for (; n; n >>= 1, x = x * x % q)
        if (n & 1)
            a = a * x % q;

    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i] >> k[i];

    ll cnt = 1, cnt2 = 1, sum = 1, pr = 1;
    for (int i = 0; i < n; i++) {
        cnt = cnt * (k[i] + 1) % M;
        sum = sum * (pw(p[i], k[i] + 1, M) - 1) % M * pw(p[i] - 1, M - 2, M) % M;
        pr = pw(pr, k[i] + 1, M) * pw(pw(p[i], s(k[i]), M), cnt2, M) % M;
        cnt2 = cnt2 * (k[i] + 1) % (M - 1);
    }

    cout << cnt << " " << sum << " " << pr << "\n";
    return 0;
}
