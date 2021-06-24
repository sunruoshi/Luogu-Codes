#include <cstdio>
#include <algorithm>
using namespace std;

int next_permute(int arr[], int n) {
    if (n < 2) return 0;
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1, k = n - 1;
        if (arr[i] >= arr[j]) continue;
        while (arr[i] >= arr[k]) k--;
        swap(arr[i], arr[k]);
        reverse(arr + j, arr + n);
        return 1;
    }
    reverse(arr, arr + n);
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    while (next_permute(arr, n)) {
        for (int i = 0; i < n; i++) {
            printf("%5d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
