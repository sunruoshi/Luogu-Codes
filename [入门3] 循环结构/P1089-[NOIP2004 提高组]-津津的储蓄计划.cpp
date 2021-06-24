#include <cstdio>

int main() {
    int cur = 0, deposit = 0;
    for (int i = 0; i < 12; ++i) {
        int budget;
        scanf("%d", &budget);
        cur += 300 - budget;
        if (cur < 0) {
            printf("-%d", i + 1);
            return 0;
        } else if (cur >= 100) {
            deposit += (cur / 100) * 100;
            cur %= 100;
        }
    }
    printf("%d", cur + deposit * 6 / 5);
    return 0;
}
