#include <cstdio>

const int MAXN = 5001;

int n, m, p;

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
    scanf("%d %d %d", &n, &m, &p);
    UnionFind uf(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        uf.Union(x, y);
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (uf.Find(x) == uf.Find(y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
