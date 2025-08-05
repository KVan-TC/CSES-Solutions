#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6+5, M = 1e9 + 7;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    int ans = 0;
    while (n) {
        int t = n, m = 0;
        while (t) {
            m = max(m, t % 10);
            t /= 10;
        }
        n -= m;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}