#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", (a + c) & 1);
    }
    return 0;
}
