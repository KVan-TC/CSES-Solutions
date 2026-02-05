#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1 << 18;
 
int n, Q;
ll st[N * 2];

void update(int p, int v) {
    p += N - 1;
    st[p] += v;
    for (p >>= 1; p; p >>= 1) 
        st[p] = max(st[p << 1], st[p << 1 | 1]);
}
 
int get(int x) {
    if (st[1] < x) return 0;
    int p = 1;
    while (p < N)
        p = p * 2 + (st[p << 1] < x);
    return p - N + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        int k = get(x);
        cout << k << " ";
        if (k) update(k, -x);
    }
    return 0;
}