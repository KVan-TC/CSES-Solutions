#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int ans = unique(a, a + n) - a;

    cout << ans << "\n";
    return 0;
}
