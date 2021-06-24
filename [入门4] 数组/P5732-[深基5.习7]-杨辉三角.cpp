#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int cur[20], prev[20];
    for (int i = 0; i < 20; ++i) {
        cur[i] = 0;
        prev[i] = 0;
    }
    cur[0] = 1;
    prev[0] = 1;
    printf("%d\n", 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) cur[j] = prev[j] + prev[j - 1];
        for (int j = 0; j < 20; ++j) {
            if (cur[j] != 0) printf("%d ", cur[j]);
            else break;
        }
        for (int j = 0; j < 20; ++j) prev[j] = cur[j];
        printf("\n");
    }
    return 0;
}
