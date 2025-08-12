#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

const int M = 1e9 + 7;

int n, m, pi[105], nxt[105][26], f[1005][105];
string S;

ll pw(ll x, ll n, ll q) {
    ll a = 1;
    x %= q;
    for (; n; x = x * x % q, n >>= 1)
        if (n & 1)
            a = a * x % q;

    return a;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> S;
    m = S.size();
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && S[i] != S[j]) j = pi[j - 1];
        if (S[i] == S[j]) j++;
        pi[i] = j;
    }

    for (int i = 0; i < m; i++)
        for (int c = 0; c < 26; c++) {
            int j = i;
            while (j > 0 && (S[j] - 'A') != c) j = pi[j - 1];
            if ((S[j] - 'A') == c) j++;
            nxt[i][c] = j;
        }

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            if (f[i - 1][j])
                for (char c = 0; c < 26; c++) {
                    int ns = nxt[j][c];
                    if (ns < m)
                        f[i][ns] = (f[i][ns] + f[i - 1][j]) % M;
                }

    ll ans = pw(26, n, M);
    for (int i = 0; i < m; i++)
        ans = (ans - f[n][i] + M) % M;

    cout << ans << "\n";

    return 0;
}