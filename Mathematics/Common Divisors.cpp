#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6;

int n, d[N+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        d[x]++;
    }

    for (int i = N; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= N; j += i) {
            cnt += d[j];
            if (cnt >= 2) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}
