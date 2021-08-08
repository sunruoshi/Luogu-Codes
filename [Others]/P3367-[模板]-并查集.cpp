#include <cstdio>

const int MAXN = 1e4 + 1;

int n, m;

struct UnionFind {
    int fa[MAXN];
    UnionFind(int n) {
        for (int i = 1; i <= n; i++) {
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
    scanf("%d %d", &n, &m);
    UnionFind uf(n);
    while (m--) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) uf.Union(x, y);
        else {
            if (uf.Find(x) == uf.Find(y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
