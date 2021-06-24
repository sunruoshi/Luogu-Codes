#include <cstdio>

int main() {
    int n, idx = 0, cur = 0;
    scanf("%d", &n);
    while (idx < n * n) {
        int d;
        scanf("%d", &d);
        for (int i = 0; i < d; ++i) {
            printf("%d", cur);
            if ((idx + i) % n == n - 1) printf("\n");
        }
        idx += d;
        cur = cur == 0 ? 1 : 0;
    }
    return 0;
}
