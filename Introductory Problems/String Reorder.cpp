#include <bits/stdc++.h>
using namespace std;

string S;
int f[26], pre[26], nxt[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S;

    int n = S.size(), mx = 0;
    for (char c : S) 
        mx = max(mx, ++f[c - 'A']);

    if (2 * mx > n + 1) return cout << "-1\n", 0;

    int pre = -1;
    for (int i = 0; i < n; i++)
        for (int nxt = 0; nxt < 26; nxt++) {
            if (!f[nxt] || pre == nxt || (f[nxt] < mx && n - i < 2 * mx)) continue;
            cout << char(nxt + 'A');
            pre = nxt;
            if (f[nxt]-- == mx) {
                mx = 0;
                for (int j = 0; j < 26; j++)
                    mx = max(mx, f[j]);
            }
            break;
        }
    cout << "\n";

    return 0;
}
