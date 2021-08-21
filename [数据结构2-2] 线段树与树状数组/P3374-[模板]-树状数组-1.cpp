#include <cstdio>
#include <cstring>
#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct BinaryIndexedTree {
    int c[MAXN];
    BinaryIndexedTree() {
        memset(c, 0, sizeof(c));
    }
    void update(int x, int v) {
        for (int i = x; i < MAXN; i += lowbit(i)) {
            c[i] += v;
        }
    }
    int getSum(int x) {
        int sum = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            sum += c[i];
        }
        return sum;
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
        else printf("%d\n", bit.getSum(y) - bit.getSum(x - 1));
    }
    return 0;
}
