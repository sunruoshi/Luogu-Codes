#include <cstdio>
#include <vector>
using namespace std;

const int N = 5e5 + 1;

int n, m, s, ans[N], fa[N];
vector<int> adj[N];
vector<pair<int, int>> q[N];
bool vis[N];

int query(int x) {
    return x == fa[x] ? x : fa[x] = query(fa[x]);
}

void tarjan(int u) {
    fa[u] = u;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for (auto e : q[u]) {
        if (vis[e.first]) {
            ans[e.second] = query(e.first);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        q[a].push_back(make_pair(b, i));
        q[b].push_back(make_pair(a, i));
    }
    tarjan(s);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}