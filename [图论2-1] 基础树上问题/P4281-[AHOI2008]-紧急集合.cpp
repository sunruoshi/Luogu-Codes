#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

int n, m, ans, p[MAXN][31], depth[MAXN];
vector<vector<int>> adj;

void dfs(int u, int fa) {
    p[u][0] = fa;
    depth[u] = depth[fa] + 1;
    for (int i = 1; (1 << i) <= depth[u]; i++) {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != fa) dfs(v, u);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int temp = depth[x] - depth[y];
    for (int i = 0; temp > 0; i++) {
        if (temp & 1) x = p[x][i];
        temp >>= 1;
    }
    if (x == y) return x;
    for (int i = 30; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int dis(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int main() {
    scanf("%d %d", &n, &m);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        int t1 = lca(x, y), t2 = lca(x, z), t3 = lca(y, z);
        if (t1 == t2 && t1 == t3) ans = t1;
        else if (t1 == t2) ans = t3;
        else if (t1 == t3) ans = t2;
        else if (t2 == t3) ans = t1;
        printf("%d %d\n", ans, dis(x, ans) + dis(y, ans) + dis(z, ans));
    }
    return 0;
}
