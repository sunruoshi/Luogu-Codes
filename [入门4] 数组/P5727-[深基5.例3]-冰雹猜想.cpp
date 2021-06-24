#include <cstdio>

int main() {
    int n, i, arr[10000];
    scanf("%d", &n);
    for (i = 0; i < 10000; ++i) {
        arr[i] = n;
        if (n == 1) break;
        else if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    for (int j = i; j >=0 ; --j) printf("%d ", arr[j]);
    return 0;
}
