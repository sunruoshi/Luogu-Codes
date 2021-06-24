#include <cstdio>

using namespace std;

int main() {
    int n, cnt = 1;
    scanf("%d", &n);
    // 打印正方形
    for (int i = 1; i <= n * n; i++) {
        if (i < 10) printf("0%d", i);
        else printf("%d", i);
        // 逢n的倍数换行
        if (i % n == 0) printf("\n");
    }
    printf("\n");
    // 打印三角形
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf("  "); // 一次要补两个空格
        while (cnt <= i * (i + 1) / 2) {
            if (cnt < 10) printf("0%d", cnt);
            else printf("%d", cnt);
            cnt++;
        }
        printf("\n");
    }
}
