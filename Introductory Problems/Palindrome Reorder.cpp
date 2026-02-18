#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int cnt[26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int n = s.size();
    for (char c : s) cnt[c - 'A']++;

    string half = "";
    int mid = -1;
    for (int i = 0; i < 26; i++) {
        half += string(cnt[i] / 2, char(i + 'A'));

        if (cnt[i] % 2 == 1) {
            if (mid != -1) return cout << "NO SOLUTION\n", 0;
            mid = i;
        }
    }
    cout << half;
    if (mid != -1) cout << char(mid + 'A');
    reverse(half.begin(), half.end());
    cout << half << "\n";

    return 0;
}