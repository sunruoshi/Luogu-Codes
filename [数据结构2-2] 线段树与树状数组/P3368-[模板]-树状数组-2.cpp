#include <cstdio>
#include <cstring>
#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

struct BinaryIndexedTree {
    int c[MAXN];
    BinaryIndexedTree() {
        memset(c, 0, sizeof(c));
    }
    int getSum(int x) {
        int sum = 0;
        for (int i = x; i < MAXN; i += lowbit(i)) {
            sum += c[i];
        }
        return sum;
    }
    void update(int x, int v) {
        for (int i = x; i > 0; i -= lowbit(i)) {
            c[i] += v;
        }
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
        bit.update(i - 1, -x);
    }
    for (int i = 1; i <= m; i++) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            bit.update(y, k);
            bit.update(x - 1, -k);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", bit.getSum(x));
        }
    }
    return 0;
}
