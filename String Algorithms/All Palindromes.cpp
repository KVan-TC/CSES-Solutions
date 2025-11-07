#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

string S;
int r[N], p[2 * N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S;
    string T = "@#";
    for (char c : S) {
        T += c;
        T += '#';
    }
    T += '$';
    int n = S.size(), m = T.size();

    for (int i = 1, pos = 0, r = 0; i < m - 1; i++) {
        int mir = 2 * pos - i;
        if (i < r) p[i] = min(r - i, p[mir]);
        while (T[i + p[i] + 1] == T[i - p[i] - 1]) p[i]++;
        if (i + p[i] > r)
            pos = i, r = i + p[i];
    }

    for (int i = 1; i < m - 1; i++) {
        int len = p[i], pos = (i + len - 2) / 2;
        r[pos] = max(r[pos], len);
    }

    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        len = max(len, r[i]);
        r[i] = len;
        len -= 2;
    }

    for (int i = 0; i < n; i++)
        cout << r[i] << " ";
    return 0;
}