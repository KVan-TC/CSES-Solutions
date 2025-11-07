#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n, mx;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    cin >> mx;
    ll ans = 0;
    for (int x; cin >> x; ) {
        mx = max(mx, x);
        ans += mx - x;
    }
    cout << ans << "\n";
    return 0;
}
