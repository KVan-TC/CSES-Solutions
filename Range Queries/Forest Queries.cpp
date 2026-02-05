#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 1e3+5;
 
int n, Q, p[N][N];

int query(int x1, int y1, int x2, int y2) {
    return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (c == '*');
        }

    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << "\n";
    }
    return 0;
}