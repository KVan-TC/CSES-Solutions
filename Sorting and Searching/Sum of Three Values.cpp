#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5+5;

int n, X;

pii a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> X;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int s = a[i].first + a[l].first + a[r].first;
            if (s == X) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            } else if (s > X) r--;
            else l++;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
