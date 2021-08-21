#include <cstdio>

#define lowbit(i) ((i) & (-i))

const int MAXN = 500001;

int c[MAXN];

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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        update(i, x);
        update(i - 1, -x);
    }
    for (int i = 1; i <= m; i++) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            update(y, k);
            update(x - 1, -k);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", getSum(x));
        }
    }
    return 0;
}
