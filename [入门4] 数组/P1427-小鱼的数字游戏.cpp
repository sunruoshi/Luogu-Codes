#include <cstdio>

int main() {
    int arr[100], i;
    for (i = 0; i < 100; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) break;
    }
    for (int j = i - 1; j >= 0; --j) printf("%d ", arr[j]);
    return 0;
}
