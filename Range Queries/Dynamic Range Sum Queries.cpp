#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, Q, a[N];
ll BIT[N];
 
void update(int p, int v) {
    for (; p <= n; p += p & -p)
        BIT[p] += v;
}
 
ll query(int p) {
    ll a = 0;
    for (; p > 0; p -= p & -p)
        a += BIT[p];
    return a;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
 
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u;
            update(k, u - a[k]);
            a[k] = u;
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }
    return 0;
}
