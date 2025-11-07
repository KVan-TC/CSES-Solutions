#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 20;

int n, Q;
ll fact[N+1];

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    init(N);
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int type; cin >> type >> n;

        ll f = fact[n];
        vector<int> p;
        for (int i = 1; i <= n; i++)
            p.push_back(i);

        if (type == 1) {
            ll k; cin >> k;
            k--;
            
            for (int i = 0; i < n; i++) {
                f /= n - i;
                cout << p[k / f] << " ";
                p.erase(p.begin() + (k / f));
                k %= f;
            }
            cout << "\n";
        } else {
            ll k = 1;

            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                f /= n - i;
                int it = find(p.begin(), p.end(), x) - p.begin();
                k += it * f;
                p.erase(p.begin() + it);
            }

            cout << k << "\n";
        }
    }
    return 0;
}
