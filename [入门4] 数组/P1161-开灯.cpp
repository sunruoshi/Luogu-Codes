#include <cstdio>

int main() {
    int n, arr[2000000];
    for (int i = 0; i < 2000000; ++i) arr[i] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int t;
        double a;
        scanf("%lf %d", &a, &t);
        for (int j = 1; j <= t; ++j) arr[int(a * j) - 1] = arr[int(a * j) - 1] == 0 ? 1 : 0;
    }
    for (int i = 0; i < 2000000; ++i) {
        if (arr[i] == 1) {
            printf("%d", i + 1);
            return 0;
        }
    }
}
