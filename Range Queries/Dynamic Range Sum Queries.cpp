#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5+5;
 
int n, Q, a[N];
ll t[N];

void update(int p, int v) {
    int d = v - a[p];
    a[p] = v;
    for (; p <= n; p += p & -p)
        t[p] += d;
}

ll query(int p) {
    ll s = 0;
    for (; p > 0; p -= p & -p)
        s += t[p];
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> Q;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }

    for (int q = 0; q < Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;

            update(k, u);

        } else {
            int l, r; cin >> l >> r;

            cout << query(r) - query(l - 1) << "\n";
        }
    }
    return 0;
}