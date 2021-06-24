#include <cstdio>

int main() {
    int freq[10], m, n;
    for (int i = 0; i < 10; ++i) freq[i] = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; ++i) {
        int d = i;
        while (d > 0) {
            freq[d % 10]++;
            d /= 10;
        }
    }
    for (int i = 0; i < 10; ++i) printf("%d ", freq[i]);
    return 0;
}
