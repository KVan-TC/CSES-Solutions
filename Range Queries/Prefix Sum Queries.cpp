#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> Node;
 
const int N = 1 << 18;
 
int n, Q, a[N];
Node st[N * 2];

Node merge(const Node& L, const Node& R) {
    return {
        L.first + R.first,
        max(L.second, L.first + R.second)
    };
}

void update(int p, int v) {
    p += N;
    st[p] = {v, max(0, v)};
    for (p >>= 1; p; p >>= 1)
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
}

Node query(int l, int r) {
    Node L = {0, 0}, R = {0, 0};
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) L = merge(L, st[l++]);
        if (!(r & 1)) R = merge(st[r--], R);
    }
    return merge(L, R);
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
            update(k, u);
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            cout << query(l, r).second << "\n";
        }
    }
    return 0;
}