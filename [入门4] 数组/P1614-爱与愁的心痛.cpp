#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n], min = 100 * m;
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    // 注意m等于n的情况
    for (int i = 0; i <= n - m; ++i) {
        int sum = 0;
        for (int j = i; j < i + m; ++j) sum += arr[j];
        min = sum < min ? sum : min;
    }
    printf("%d", min);
    return 0;
}
