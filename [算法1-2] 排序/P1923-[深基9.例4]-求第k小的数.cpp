#include <cstdio>
#include <algorithm>
using namespace std;

int find_k(int arr[], int rk, int left, int right) {
    int pivot = arr[(left + right) / 2], i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    if (rk <= j) return find_k(arr, rk, left, j);
    else if (rk >= i) return find_k(arr, rk, i, right);
    return pivot;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", find_k(arr, k, 0, n - 1));
    return 0;
}
