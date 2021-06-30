#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, ans, arr[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1]) ans += arr[i] - arr[i - 1];
    }
    printf("%d", ans);
    return 0;
}
