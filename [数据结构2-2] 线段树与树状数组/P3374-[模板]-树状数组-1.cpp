#include <cstdio>
#include <cstring>
#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct BinaryIndexedTree {
    int c[MAXN];
    BinaryIndexedTree() {
        memset(c, 0, sizeof(c));
    }
    void update(int pos, int v) {
        while (pos < MAXN) {
            c[pos] += v;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int res = 0;
        while (pos > 0) {
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    BinaryIndexedTree bit;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        bit.update(i, x);
    }
    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) bit.update(x, y);
        else printf("%d\n", bit.query(y) - bit.query(x - 1));
    }
    return 0;
}
