#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[45];
unordered_map<ll, int> f;
ll ans, X;

void Try1(int i, ll s) {
    if (s > X) return;
    if (i == n / 2) {
        f[s]++;
        return;
    }

    Try1(i + 1, s);
    Try1(i + 1, s + a[i]);
}

void Try2(int i, ll s) {
    if (s > X) return;
    if (i == n) {
        if (f.find(X - s) != f.end())
        ans += f[X - s];
        return;
    }

    Try2(i + 1, s);
    Try2(i + 1, s + a[i]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> X;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    f.reserve(1 << (n / 2));
    Try1(0, 0);
    Try2(n / 2, 0);

    cout << ans << "\n";
    return 0;
}
