#include <cstdio>

const int MAXN = 1000;

int n, m, fa[MAXN];

int Find(int x) {
    if (x != fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    int xx = Find(x), yy = Find(y);
    fa[xx] = yy;
}

int main() {
    while (1) {
        scanf("%d", &n);
        if (!n) return 0;
        scanf("%d", &m);
        if (!m) {
            printf("%d\n", n - 1);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i == Find(i)) ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
