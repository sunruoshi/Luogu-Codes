#include <bits/stdc++.h>
using namespace std;

const int LEN = 20;

int arr[LEN];

void init() {
    for (int i = 0; i < LEN; i++) {
        arr[i] = rand() % 100;
    }
}

void printArr(int arr[]) {
    for (int i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 冒泡排序
void bubbleSort() {
    int res[LEN];
    copy(arr, arr + LEN, res);
    // 外层循环从后往前遍历
    for (int i = LEN - 1; i > 0; i--) {
        // 使用标记，标记内层循环中是否发生了元素交换
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (res[j] > res[j + 1]) {
                swap(res[j], res[j + 1]);
                flag = false;
            }
        }
        // 如果内层循环中没有发生交换，说明序列已经有序
        if (flag) break;
    }
    printArr(res);
}

// 选择排序
void selectSort() {
    int res[LEN];
    copy(arr, arr + LEN, res);
    for (int i = 0; i < LEN - 1; i++) {
        int k = i;
        // 找到未排序序列中的最小值
        for (int j = i + 1; j < LEN; j++) {
            if (res[j] < res[k]) k = j;
        }
        // 将最小值放到序列最前面
        swap(res[i], res[k]);
    }
    printArr(res);
}

// 二分插入排序
void insertSort() {
    int res[LEN];
    copy(arr, arr + LEN, res);
    // 认为序列第一个元素已经有序
    for (int i = 1; i < LEN; i++) {
        // 二分查找插入位置
        int temp = res[i], left = 0, right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (res[mid] > temp) right = mid - 1;
            else left = mid + 1;
        }
        // 将插入位置之后的元素全部右移一位
        for (int j = i - 1; j >= left; j--) {
            res[j + 1] = res[j];
        }
        // 将未排序的元素插入
        if (left != i) res[left] = temp;
    }
    printArr(res);
}


// 计数排序
void countingSort() {
    int res[LEN];
    copy(arr, arr + LEN, res);
    int maxn = 0;
    // 找出序列中的最大值
    for (int i = 0; i < LEN; i++) {
        if (res[i] > maxn) maxn = res[i];
    }
    // 使用频度数组计数
    // 数组使用前需要初始化
    int freq[maxn + 1];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < LEN; i++) {
        freq[res[i]]++;
    }
    int pos = 0;
    // 将频度数组中的元素修改回原数组
    for (int i = 0; i <= maxn; i++) {
        while (freq[i]--) res[pos++] = i;
    }
    printArr(res);
}

// 快速排序
void quickSort(int num[], int left, int right) {
    if (left >= right) return;
    // 基准数可以任意选取，这里取序列中间的数为基准数
    int pivot = num[left + (right - left) / 2], i = left, j = right;
    while (i <= j) {
        while (num[i] < pivot) i++; // 找到基准数左边第一个大于基准数的元素
        while (num[j] > pivot) j--; // 找到基准数右边第一个小于基准数的元素
        if (i <= j) swap(num[i++], num[j--]); // 交换这两个元素
    }
    // 递归的操作基准数左右两边的区间
    quickSort(num, left, j);
    quickSort(num, i, right);
}

// 归并排序
void mergeSort(int num[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(num, left, mid);
    mergeSort(num, mid + 1, right);
    int i = left, j = mid + 1, pos = 0, temp[right - left + 1];
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) temp[pos++] = num[i++];
        else temp[pos++] = num[j++];
    }
    while (i <= mid) temp[pos++] = num[i++];
    while (j <= right) temp[pos++] = num[j++];
    copy(temp, temp + right - left + 1, num + left);
}

int main() {
    init();

    int num[LEN];

    printf("冒泡排序：");
    bubbleSort();

    printf("选择排序：");
    selectSort();

    printf("插入排序：");
    insertSort();

    printf("计数排序：");
    countingSort();

    printf("快速排序：");
    copy(arr, arr + LEN, num);
    quickSort(num, 0, LEN - 1);
    printArr(num);

    printf("归并排序：");
    copy(arr, arr + LEN, num);
    mergeSort(num, 0, LEN - 1);
    printArr(num);

    printf("  未排序：");
    printArr(arr);

    return 0;
}
