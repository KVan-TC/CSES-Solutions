#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

string s;
int cnt[26];

bool check(int len) {
    for (int i = 0; i < 26; i++)
        if (2 * cnt[i] > len + 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> s;
    int n = s.size();
    for (char c : s) cnt[c - 'A']++;

    if (!check(n)) return cout << "-1\n", 0;

    int prev = -1;
    for (int i = 1; i <= n; i++) 
        for (int nxt = 0; nxt < 26; nxt++) {
            if (prev == nxt || !cnt[nxt]) continue;
            cnt[nxt]--;
            if (check(n - i)) {
                cout << char(nxt + 'A');
                prev = nxt;
                break;
            }
            cnt[nxt]++;
        }
    cout << "\n";

    return 0;
}
