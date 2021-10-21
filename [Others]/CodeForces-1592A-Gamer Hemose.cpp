#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, h;
        scanf("%d %d", &n, &h);
        int max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++) {
            int w;
            scanf("%d", &w);
            if (w > max1) {
                max2 = max1;
                max1 = w;
            } else if (w > max2) {
                max2 = w;
            }
        }
        int res = h / (max1 + max2), mod = h % (max1 + max2), k = 0;
        if (mod) {
            if (mod <= max1) k = 1;
            else k = 2;
        }
        printf("%d\n", (res << 1) + k);
    }
    return 0;
}
