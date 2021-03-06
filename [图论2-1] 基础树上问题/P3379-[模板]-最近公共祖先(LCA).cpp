#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

vector<vector<int>> adj;
int p[MAXN][31], depth[MAXN];

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
    int n, m, root;
    scanf("%d %d %d", &n, &m, &root);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(root, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}
