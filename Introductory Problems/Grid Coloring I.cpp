#include <bits/stdc++.h>
using namespace std;

const char ch[2][2] = {{'A', 'B'}, {'C', 'D'}};
const int N = 505;

int n, m, d[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;

            cout << ch[c < 'C'][(i + j) & 1];
        }
        cout << "\n";
    }

    return 0;
}
