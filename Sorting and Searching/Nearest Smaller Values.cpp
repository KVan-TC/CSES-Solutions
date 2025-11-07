#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5+5;
 
int n, a[N], ans[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) ans[i] = 0;
        else ans[i] = s.top();
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}