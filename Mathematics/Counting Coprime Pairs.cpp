#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int X = 1e6;

ll ans;
int n, mu[X+1], cnt[X+1];
bool np[X+1];
vector<int> pr;

void init(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!np[i]) {
            pr.push_back(i);
            mu[i] = -1;
        }
        for (int p : pr) {
            if (p * i > n) break;
            np[p * i] = 1;
            if (i % p == 0) break;
            mu[p * i] = mu[p] * mu[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    init(X);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    for (int p : pr)
        for (int i = X / p; i > 0; i--)
            cnt[i] += cnt[p * i];

    for (int i = 1; i <= X; i++)
        if (mu[i]) ans += 1LL * mu[i] * cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << "\n";
    return 0;
}
