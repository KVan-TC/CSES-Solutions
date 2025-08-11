#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int f[8], ans, mask = (1 << 8) - 1;

void dfs(int r, int c, int d1, int d2) {
    if (r == 8) {
        ans++;
        return;
    }

    int p = f[r] & ~(c | d1 | d2) & mask;
    while (p) {
        int b = p & -p;
        p -= b;
        dfs(r + 1, c | b, (d1 | b) << 1, (d2 | b) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    for (int r = 0; r < 8; r++) {
        string s; cin >> s;
        int m = 0;
        for (int c = 0; c < 8; c++)
            if (s[c] == '.') m |= (1 << c);
        f[r] = m;
    }

    dfs(0, 0, 0, 0);
    cout << ans << "\n";
    return 0;
}
