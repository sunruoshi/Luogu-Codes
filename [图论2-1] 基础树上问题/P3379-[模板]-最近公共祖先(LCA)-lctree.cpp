#include <cstdio>
#include <vector>
using namespace std;

const int N = 5e5 + 1;

int n, m, s;
int fa[N], depth[N], siz[N], son[N], top[N];
vector<int> adj[N];

void dfs1(int u) {
    siz[u] = 1;
    depth[u] = depth[fa[u]] + 1;
    for (int v : adj[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int v : adj[u]) {
        if (v != son[u] && v != fa[u]) dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (depth[top[u]] > depth[top[v]]) {
            u = fa[top[u]];
        } else {
            v = fa[top[v]];
        }
    }
    return depth[u] < depth[v] ? u : v;
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(s);
    dfs2(s, s);
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
