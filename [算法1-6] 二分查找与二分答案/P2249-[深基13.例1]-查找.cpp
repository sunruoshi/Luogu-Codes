#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;

int n, m, arr[MAXN];

int binarySearch(int x) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x) right = mid;
        else left = mid + 1;
    }
    return arr[left] == x ? left : -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        printf("%d ", binarySearch(x));
    }
    return 0;
}
