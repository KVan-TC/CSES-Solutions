#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5+5;

int n;
vector<pii> p;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        p.push_back({a, 1});
        p.push_back({b, -1});
    }
    
    sort(p.begin(), p.end());

    int sum = 0, ans = 0;
    for (pii x : p) {
        sum += x.second;
        ans = max(ans, sum);
    }

    cout << ans << "\n";
    return 0;
}