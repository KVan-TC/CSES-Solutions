#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
 
using ll = long long;
using pii = pair<int, int>;
 
const int N = 2e5+5;
const int M = 1e9 + 7;
 
int n;
ll t[N];
pii a[N];
 
void update(int i, int v) {
    for (; i <= N; i += i & -i)
        t[i] = (t[i] + v) % M;
}
 
ll query(int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s = (s + t[i]) % M;
    return s;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }
 
    sort(a, a + n, [](pii &a, pii &b) {
        if (a.fi == b.fi) return b.se < a.se;
        return a.fi < b.fi;
    });
 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = a[i].se;
        ll t = query(idx) + 1;
        ans = (ans + t) % M;
        update(idx, t);
    }
    cout << ans << "\n";
    return 0;
}
