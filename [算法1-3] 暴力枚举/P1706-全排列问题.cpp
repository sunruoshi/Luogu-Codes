#include <bits/stdc++.h>
using namespace std;

int n, arr[9];

int next_permute() {
    if (n < 2) return 0;
    // 从后往前查找第一个相邻的元素对(i, j), 满足arr[i] < arr[j]
    for (int i = n - 2; i >= 0; i--) {
        int j = i + 1, k = n - 1;
        if (arr[i] >= arr[j]) continue;
        // 在[j, end)中寻找一个最小的k, 满足arr[i] < arr[k]
        while (arr[i] >= arr[k]) k--;
        // 交换arr[i]和arr[k]的值
        swap(arr[i], arr[k]);
        // 反转[j, end)
        reverse(arr + j, arr + n);
        return 1;
    }
    // 如果没有找到符合要求的相邻元素对(i, j)，则说明原序列为降序，没有下一个全排列
    // STL的方法是将序列逆置成升序
    reverse(arr, arr + n);
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    while (next_permute()) {
        for (int i = 0; i < n; i++) {
            printf("%5d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
