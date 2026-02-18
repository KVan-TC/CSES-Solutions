#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int N = 8;
const int MASK = (1 << N) - 1;

int f[N], ans;

void dfs(int r, int c, int d1, int d2) {
    if (r == N) { 
        ans++;
        return;
    }

    int p = f[r] & ~(c | d1 | d2) & MASK;
    while (p) {
        int b = p & -p;
        p -= b;
        dfs(r + 1, c | b, (d1 | b) << 1, (d2 | b) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    for (int r = 0; r < N; r++) {
        int mask = MASK;
        for (int c = 0; c < N; c++) {
            char ch; cin >> ch;
            if (ch == '*') mask ^= (1 << c);
        }
        f[r] = mask;
    }

    dfs(0, 0, 0, 0);
    cout << ans << "\n";

    return 0;
}
