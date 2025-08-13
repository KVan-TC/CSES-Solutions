#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5+5;
const int M = 1e9 + 7;
 
int n, p[N], cnt[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++)
        if (p[i]) {
            int u = i, len = 0;

            do {
                len++;
                int v = p[u];
                p[u] = 0;
                u = v;
            } while (u != i);

            for (int x = 2; x * x <= len; x++) {
                int c = 0;
                while (len % x == 0)
                    c++, len /= x;
                cnt[x] = max(cnt[x], c);
            }
            if (!cnt[len]) cnt[len] = 1;
        }

    ll ans = 1;
    for (int x = 2; x <= n; x++)
        for (int i = 0; i < cnt[x]; i++)
            ans = ans * x % M;
 
    cout << ans << "\n";
    return 0;
}
