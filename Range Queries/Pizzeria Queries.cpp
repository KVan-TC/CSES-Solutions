#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1 << 18;
const int oo = 2e9;
 
int n, Q;

struct ST {
    vector<int> st; 

    ST(int n = 0) : st(N * 2, oo) {}

    void update(int p, int v) {
        p += N;
        st[p] = v;
        for (p >>= 1; p; p >>= 1)
            st[p] = min(st[p << 1], st[p << 1 | 1]);
    }

    int query(int l, int r) {
        int s = oo;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) s = min(s, st[l++]);
            if (!(r & 1)) s = min(s, st[r--]);
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;

    ST L, R;
    auto add = [&](int i, int x) {
        L.update(i, x - i);
        R.update(i, x + i);
    };

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        add(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u;
            add(k, u);
        } else if (t == 2) {
            int k; cin >> k;
            cout << min(L.query(1, k) + k, R.query(k, n) - k) << "\n";
        }
    }
    return 0;
}