#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5+5;

int n;
pii p[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].second >> p[i].first;

    sort(p, p + n);

    ll t = 0, ans = 0;
    for (pii x : p) 
        if (x.second >= t)
            ans++, t = x.first;

    cout << ans << "\n";
    return 0;
}