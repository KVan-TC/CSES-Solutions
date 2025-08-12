#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 2e5+5;
 
int n, a, b;
ll p[N];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        p[i] = p[i - 1] + x;
    }

    ll ans = -1e18;
    deque<int> dq;
    for (int r = a; r <= n; r++) {
        int l1 = max(0, r - b), l2 = r - a;

        while (!dq.empty() && dq.front() < l1) dq.pop_front();

        if (l2 >= 0) {
            while (!dq.empty() && p[dq.back()] >= p[l2]) dq.pop_back();
            dq.push_back(l2);
        }

        if (!dq.empty()) ans = max(ans, p[r] - p[dq.front()]);
    }

    cout << ans << "\n";
    return 0;
}