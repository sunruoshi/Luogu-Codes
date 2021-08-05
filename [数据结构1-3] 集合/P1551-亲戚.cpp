#include <cstdio>

const int MAXN = 5001;

int n, m, p, fa[MAXN];

int Find(int x) {
    if (x != fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    int xx = Find(x), yy = Find(y);
    fa[xx] = yy;
}

int main() {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Union(x, y);
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (Find(x) == Find(y)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
