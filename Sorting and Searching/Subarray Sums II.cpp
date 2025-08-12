#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int n, X;
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> X;

    ll s = 0, ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s += x;
        ans += cnt[s - X];
        cnt[s]++;
    }

    cout << ans << "\n";
    return 0;
}