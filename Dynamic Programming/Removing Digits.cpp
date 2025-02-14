#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    int ans = 0;

    while (n) {
        int a = n, b = 0;
        while (a) {
            b = max(b, a % 10);
            a /= 10;
        }
        n -= b;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}