#include <cstdio>

int main() {
    int s1, s2, s3, max = 0;
    scanf("%d %d %d", &s1, &s2, &s3);
    int cnt[81];
    for (int i = 3; i < 81; ++i) cnt[i] = 0;
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                cnt[i + j + k]++;
                max = cnt[i + j + k] > max ? cnt[i + j + k] : max;
            }
        }
    }
    for (int i = 3; i < 81; ++i) {
        if (cnt[i] == max) {
            printf("%d", i);
            return 0;
        }
    }
}
