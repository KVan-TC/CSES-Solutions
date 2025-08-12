#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5+5;
 
int n, k, a[N];
map<int, int> mp;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    ll ans = 0;
    for (int l = 0, r = 0, cnt = 0; r < n; r++) {
        if (++mp[a[r]] == 1) cnt++;
        while (cnt > k)
            if (--mp[a[l++]] == 0) cnt--;
        ans += r - l + 1;
    }
 
    cout << ans << "\n";
    return 0;
}