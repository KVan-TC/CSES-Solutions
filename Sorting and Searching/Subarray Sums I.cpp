#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
 
int n, X, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> X;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0, s = 0;
    for (int l = 1, r = 1; l <= n; l++) {
        while (r <= n && s < X) s += a[r++];
        if (s == X) ans++;
        s -= a[l];
    }

    cout << ans << "\n";
    return 0;
}