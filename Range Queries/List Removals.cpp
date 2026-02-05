#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1 << 18;
 
int n, a[N], st[N * 2];
 
void update(int p, int v) {
    p += N;
    st[p] += v;
    for (p >>= 1; p; p >>= 1)
        st[p] = st[p << 1] + st[p << 1 | 1];
}
 
int findKth(int k) {
    int p = 1;
    while (p < N)
        if (st[p << 1] >= k)
            p = p << 1;
        else
            k -= st[p << 1], p = p << 1 | 1;
    return p - N;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, 1);
    }
 
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        int k = findKth(p);
        cout << a[k] << " ";
        update(k, -1);
    }
    return 0;
}