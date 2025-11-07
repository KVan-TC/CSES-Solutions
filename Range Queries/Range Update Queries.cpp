#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, Q, a[N];
ll t[N];

void update(int p, int v) {
    for (; p <= n; p += p & -p)
        t[p] += v;
}

void add(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
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
        cin >> a[i];
        add(i, i, a[i]);
    }

    for (int q = 0; q < Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, v; cin >> l >> r >> v;

            add(l, r, v);
        } else {
            int k; cin >> k;

            cout << query(k) << "\n";
        }
    }
    return 0;
}