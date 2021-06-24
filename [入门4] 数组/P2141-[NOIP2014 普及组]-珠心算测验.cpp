#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for (int i = 2; i < n; ++i) {
        int find = 0;
        for (int j = 0; j < i - 1; ++j) {
            for (int k = j + 1; k < i; ++k) {
                if (arr[j] + arr[k] == arr[i]) {
                    cnt++;
                    find = 1;
                    break;
                }
            }
            if (find == 1) break;
        }
    }
    printf("%d", cnt);
    return 0;
}
