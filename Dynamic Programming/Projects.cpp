#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

struct Project {
    int s, e;
    ll v;
    bool operator<(Project& b) const { return e < b.e; }
};

int n;
ll f[N];
vector<ll> dp = {0};
Project P[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, p; cin >> a >> b >> p;
        P[i] = {a, b, p};
    }

    sort(P, P + n);

    int idx = 0;
    ll ans = 0;
    f[0] = 0;
    for (auto &[s, e, v] : P) {
        int it = lower_bound(dp.begin(), dp.end(), s) - dp.begin() - 1;
        v += f[it];
        if (ans >= v) continue;
        ans = v;
        f[++idx] = v;
        dp.push_back(e);
    }
    cout << ans << "\n";
    return 0;
}
