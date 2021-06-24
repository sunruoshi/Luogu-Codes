#include <iostream>
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
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (m--) {
        next_permute(arr, n);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
