#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6;

int n, d[N+1];

void init(int n) {
    for (int i = 1; i * i <= n; i++)
        for (int j = i * i; j <= n; j += i) {
            d[j] += 2;
            if (i * i == j) d[j]--;
        }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    init(N);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << d[x] << "\n";
    }
    return 0;
}
