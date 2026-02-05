#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
const int oo = 1e9;
 
int n, Q, a[N], ST[N << 1];
 
void update(int p, int v) {
    p += n;
    ST[p] = v;
    for (p >>= 1; p > 0; p >>= 1)
        ST[p] = min(ST[p << 1], ST[p << 1 | 1]);
}
 
int query(int l, int r) {
    int a = oo;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) a = min(a, ST[l++]);
        if (!(r & 1)) a = min(a, ST[r--]);
    }
    return a;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= 2 * n; i++)
        ST[i] = oo;
 
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
 
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u;
            update(k, u);
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            cout << query(l, r) << "\n";
        }
    }
    return 0;
}
