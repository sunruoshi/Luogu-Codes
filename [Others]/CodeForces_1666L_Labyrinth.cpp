#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e5 + 1;

int n, m, s, from[MAXN], pre[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void print_path(int u, int cnt) {
    if (!pre[u]) {
        cout << cnt << endl << u << ' ';
        return;
    }
    print_path(pre[u], cnt + 1);
    cout << u << ' ';
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
                from[v] = u == s ? v : from[u];
                pre[v] = u;
            } else {
                if (v == s) continue;
                if (u == s || from[u] != from[v]) {
                    cout << "Possible" << endl;
                    print_path(u, 2);
                    cout << v << endl;
                    print_path(v, 1);
                    return 0;
                }
            }
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
