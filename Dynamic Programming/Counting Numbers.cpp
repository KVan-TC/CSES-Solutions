#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;
bool t[20];
ll f[10][20];

ll g(ll x) {
    if (x <= 10) return x;
    vector<int> a;
    memset(f, 0, sizeof(f));
    memset(t, 0, sizeof(t));

    for (; x; x /= 10)
        a.push_back(x % 10);
    reverse(a.begin(), a.end());

    int n = a.size();
    t[0] = 1;
    for (int i = 1; i < n; i++)
        t[i] = t[i - 1] && (a[i] != a[i - 1]);
    for (int c = 1; c < a[0]; c++)
        f[c][0] = 1;
    for (int i = 1; i < n; i++) {
        if (t[i - 1])
            for (int c = 0; c < a[i]; c++)
                if (c != a[i - 1])
                    f[c][i]++;
        for (int c = 1; c <= 9; c++)
            f[c][i]++;
        for (int c1 = 0; c1 <= 9; c1++)
            for (int c2 = 0; c2 <= 9; c2++)
                if (c1 != c2)
                    f[c2][i] += f[c1][i - 1];
    }

    ll cnt = t[n - 1];
    for (int c = 0; c <= 9; c++)
        cnt += f[c][n - 1];

    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    cout << g(b) - g(a - 1) << "\n";
    return 0;
}
