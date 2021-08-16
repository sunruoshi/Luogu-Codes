#include <cstdio>

const int MAXN = 200;

struct UnionFind {
    int fa[MAXN];
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int Find(int x) {
        if (x != fa[x]) fa[x] = Find(fa[x]);
        return fa[x];
    }
    void Union(int x, int y) {
        fa[Find(x)] = Find(y);
    }
};

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    UnionFind uf(n);
    int isConnected[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (isConnected[i][j]) uf.Union(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == uf.Find(i)) ans++;
    }
    printf("%d", ans);
    return 0;
}
