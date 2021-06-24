#include <cstdio>

using namespace std;

int main() {
    int n, max = 1, cnt = 1, cur, prev = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        cnt = cur - prev == 1 ? cnt + 1 : 1;
        max = cnt > max ? cnt : max;
        prev = cur;
    }
    printf("%d", max);
    return 0;
}
