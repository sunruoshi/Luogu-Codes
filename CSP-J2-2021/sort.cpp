#include <cstdio>

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n, q;
    scanf("%d %d", &n, &q);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    while (q--) {
        int opt, x, v;
        scanf("%d %d", &opt, &x);
        if (opt == 1) {
            scanf("%d", &v);
            a[x] = v;
        } else {
            int cntL = 0, cntR = 0;
            for (int i = x - 1; i > 0; i--) {
                if (a[i] > a[x]) cntL++;
            }
            for (int i = x + 1; i <= n; i++) {
                if (a[i] < a[x]) cntR++;
            }
            printf("%d\n", x - cntL + cntR);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
