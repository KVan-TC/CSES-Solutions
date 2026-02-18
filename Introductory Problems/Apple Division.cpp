#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int n, a[25];
ll S, ans = 1e18;

void Try(int i, ll s) {
    if (s * 2 > S) return;

    if (i == n) {
        ans = min(ans, S - 2 * s);
        return;
    }

    Try(i + 1, s);
    Try(i + 1, s + a[i]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], S += a[i];

    Try(0, 0);

    cout << ans << "\n";
    
    return 0;
}
