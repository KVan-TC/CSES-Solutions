#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, h, f;
stack<pii> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    s.push({2e9, 0});
    for (cin >> n; cin >> h; f = 1) {
        for (; s.top().first < h; s.top().second = max(s.top().second, f))
            f = s.top().second + 1, s.pop();
        if (h != s.top().first)
            s.push({h, f});
    }
    for (; s.size() > 2; s.top().second = max(s.top().second, f))
        f = s.top().second + 1, s.pop();

    cout << s.top().second << "\n";
    return 0;
}
