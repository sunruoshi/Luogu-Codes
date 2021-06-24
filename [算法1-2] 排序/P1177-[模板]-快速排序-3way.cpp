#include <iostream>
using namespace std;

void quick_sort(int arr[], int n) {
    if (n <= 1) return;
    int pivot = arr[n / 2], i = 0, j = 0, k = n;
    while (i < k) {
        if (arr[i] < pivot) swap(arr[i++], arr[j++]);
        else if (arr[i] > pivot) swap(arr[i], arr[--k]);
        else i++;
    }
    quick_sort(arr, j);
    quick_sort(arr + k, n - k);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
