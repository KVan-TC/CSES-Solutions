#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;

int n, h, f;
stack<pii> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    s.push({2e9, 0});
    for (cin >> n; cin >> h; f = 1) {
        for (; s.top().fi < h; s.top().se = max(s.top().se, f))
            f = s.top().second + 1, s.pop();
        if (h != s.top().fi)
            s.push({h, f});
    }
    for (; s.size() > 2; s.top().se = max(s.top().se, f))
        f = s.top().se + 1, s.pop();

    cout << s.top().se << "\n";
    return 0;
}
