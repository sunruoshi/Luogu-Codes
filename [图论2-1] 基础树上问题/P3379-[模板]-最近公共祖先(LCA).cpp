#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500001
using namespace std;

vector<vector<int>> node;
int fa[MAXN][31], depth[MAXN];

void dfs(int root, int parent) {
    fa[root][0] = parent;
    depth[root] = depth[parent] + 1;
    for (int i = 1; (1 << i) <= depth[root]; i++) {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    for (int v : node[root]) {
        if (v != parent) dfs(v, root);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int temp = depth[x] - depth[y];
    for (int i = 0; temp > 0; i++) {
        if (temp & 1) x = fa[x][i];
        temp >>= 1;
    }
    if (x == y) return x;
    for (int i = 30; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main() {
    int n, m, root;
    scanf("%d %d %d", &n, &m, &root);
    node.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(root, 0);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}
