#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;;

int n, m, ts[N];
vector<int> adj[N];

bool dfs(int u, int t) {
    if (ts[u]) return ts[u] == t;
    ts[u] = t;
    for (int v : adj[u])
        if (!dfs(v, 3 - t)) return false;
    return true; 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (ts[i]) continue;
        if (!dfs(i, 1)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ts[i] << " ";
    cout << "\n";
    return 0;
}