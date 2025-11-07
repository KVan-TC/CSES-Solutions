#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
 
int n, Q, a[N], t[4 * N];

void pull(int i) {
    t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void build(int i, int l, int r) {
    if (l == r) {
        t[i] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    pull(i);
}

void update(int i, int l, int r, int p, int v) {
    if (l == r) {
        t[i] = v;
        return;
    }

    int m = (l + r) >> 1;
    if (p <= m) update(i << 1, l, m, p, v);
    else update(i << 1 | 1, m + 1, r, p, v);
    pull(i);
}

ll query(int i, int l, int r, int u, int v) {
    if (v < l || r < u) return 1e9;
    if (u <= l && r <= v) return t[i];
    int m = (l + r) >> 1;
    return min(query(i << 1, l, m, u, v), query(i << 1 | 1, m + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> Q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    for (int q = 0; q < Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;

            update(1, 1, n, k, u);

        } else {
            int l, r; cin >> l >> r;

            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}