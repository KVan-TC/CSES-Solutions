#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;;

int n, m, p[N];
bool used[N];
vector<int> adj[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    for (int i = 2; i <= n; i++)
        p[i] = -1;
    p[1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (u == n) {
            int v = u;
            vector<int> path;
            while (p[v]) {
                path.push_back(v);
                v = p[v];
            }
            path.push_back(v);
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (int x : path)
                cout << x << " ";
            cout << "\n";
            return 0;
        }

        for (int v : adj[u])
            if (p[v] == -1) {
                p[v] = u;
                q.push(v);
            }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}