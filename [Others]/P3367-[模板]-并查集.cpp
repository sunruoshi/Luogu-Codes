#include <cstdio>

const int MAXN = 1e4 + 1;

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
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    while (m--) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) Union(x, y);
        else {
            if (Find(x) == Find(y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
