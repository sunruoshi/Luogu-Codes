#include <cstdio>

int main() {
    int n, x, cnt = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur != 0) {
            if (cur % 10 == x) cnt++;
            cur /= 10;
        }
    }
    printf("%d", cnt);
    return 0;
}
