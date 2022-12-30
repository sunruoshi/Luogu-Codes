#include <cstdio>
#include <vector>
using namespace std;

const int N = 5e5 + 1;

int n, m, s, depth[N], p[N][21], lg[N];
vector<int> adj[N];

void dfs(int u, int fa) {
    p[u][0] = fa;
    depth[u] = depth[fa] + 1;
    for (int i = 1; i <= lg[depth[u]]; i++) {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != fa) dfs(v, u);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    while (depth[x] > depth[y]) {
        x = p[x][lg[depth[x] - depth[y]]];
    }
    if (x == y) return x;
    for (int i = lg[depth[x]]; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    dfs(s, 0);
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}