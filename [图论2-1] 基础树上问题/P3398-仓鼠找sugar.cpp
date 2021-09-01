#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100001
using namespace std;

vector<vector<int>> adj;
int n, q, p[MAXN][31], depth[MAXN];

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

int main() {
    scanf("%d %d", &n, &q);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    auto dis = [&](int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    };
    while (q--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int x = lca(a, b), y = lca(c, d);
        if (dis(a, y) + dis(b, y) == dis(a, b) || dis(c, x) + dis(d, x) == dis(c, d)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
