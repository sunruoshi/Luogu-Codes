#include <iostream>
using namespace std;

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2], i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
