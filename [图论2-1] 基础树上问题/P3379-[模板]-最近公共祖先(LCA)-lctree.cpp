#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

int n, m, root;
int fa[MAXN], depth[MAXN], siz[MAXN], son[MAXN], top[MAXN];
vector<int> adj[MAXN];

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
        if (depth[top[u]] > depth[top[v]])
            u = fa[top[u]];
        else
            v = fa[top[v]];
    }
    return depth[u] < depth[v] ? u : v;
}

int main() {
    scanf("%d %d %d", &n, &m, &root);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(root);
    dfs2(root, root);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}
