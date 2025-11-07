#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+5;
const int M = 1e9 + 7;

int k, p, f[5005], trie[N][26];
bool leaf[N];
string S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> S >> k;
    for (int i = 0; i < k; i++) {
        string w; cin >> w;
        int node = 0;
        for (char ch : w) {
            int c = ch - 'a';
            if (!trie[node][c]) {
                trie[node][c] = ++p;
            }
            node = trie[node][c];
        }
        leaf[node] = true;
    }

    int n = S.size();
    f[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int node = 0;
        for (int j = i; j < n; j++) {
            int c = S[j] - 'a';
            node = trie[node][c];
            if (!node) break;
            if (leaf[node])
                f[i] = (f[i] + f[j + 1]) % M;
        }
    }

    cout << f[0] << "\n";
    return 0;
}
