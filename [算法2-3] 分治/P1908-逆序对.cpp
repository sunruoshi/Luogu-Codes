#include <cstdio>
#include <algorithm>
using namespace std;

long long mergeSort(int nums[], int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    long long inv_count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
    int i = left, j = mid + 1, pos = 0, temp[right - left + 1];
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[pos++] = nums[i++];
            inv_count += j - mid - 1;
        } else {
            temp[pos++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[pos++] = nums[i++];
        inv_count += j - mid - 1;
    }
    while (j <= right) {
        temp[pos++] = nums[j++];
    }
    copy(temp, temp + right - left + 1, nums + left);
    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("%ld", mergeSort(nums, 0, n - 1));
    return 0;
}

