#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> Node;

const int N = 2e5+5;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> k;
    ll base = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            base += a[i];
            a[i] = -a[i];
        }
    }

    sort(a, a + n);

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({0, 0});

    while (k--) {
        Node u = pq.top(); pq.pop();
        ll sum = u.first; int i = u.second;

        cout << base + sum << " ";

        if (i < n) {
            pq.push({sum + a[i], i + 1});

            if (i > 0)
                pq.push({sum - a[i - 1] + a[i], i + 1});
        }
    }
    return 0;
}