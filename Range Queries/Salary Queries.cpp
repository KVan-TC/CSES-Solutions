#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
 
int n, m, Q, a[N], BIT[N * 2];
vector<int> v;
vector<pair<char, pair<int, int>>> q;

void update(int p, int v) {
    for (; p <= n; p += p & -p)
        BIT[p] += v;
}

int query(int p) {
    int s = 0;
    for (; p > 0; p -= p & -p)
        s += BIT[p];
    return s;
}

int query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> m >> Q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    for (int i = 0; i < Q; i++) {
        char t; int x, y; cin >> t >> x >> y;
        q.push_back({t, {x, y}});
        if (t == '!') v.push_back(y);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();

    auto get = [&](int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    };

    for (int i = 1; i <= m; i++)
        update(get(a[i]), 1);
 
    for (pair<char, pair<int, int>> p : q) {
        char t = p.first;
        int x = p.second.first, y = p.second.second;

        if (t == '!') {
            update(get(a[x]), -1);
            a[x] = y;
            update(get(a[x]), 1);
        } else {
            int L = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
            int R = upper_bound(v.begin(), v.end(), y) - v.begin();
            if (L > R) cout << "0\n";
            else cout << query(L, R) << "\n";
        }
    }
    return 0;
}