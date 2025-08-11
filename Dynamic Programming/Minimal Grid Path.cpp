#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3005;
const int dx[] = {0, 1}, dy[] = {1, 0};

int n;
string c[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    string ans = "";
    ans += c[0][0];
    vector<int> cur = {0};

    for (int s = 1; s < 2 * n - 1; s++) {
        vector<int> nxt;
        char mn = 'Z' + 1;

        for (int x : cur) {
            int y = s - x - 1;
            for (int k = 0; k < 2; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < n && ny < n) {
                    char ch = c[nx][ny];
                    if (ch < mn) {
                        mn = ch;
                        nxt.clear();
                        nxt.push_back(nx);
                    } else if (ch == mn) {
                        if (nxt.empty() || nxt.back() != nx)
                            nxt.push_back(nx);
                    }
                }
            }
        }

        ans += mn;
        cur = nxt;
    }

    cout << ans << "\n";
    return 0;
}
