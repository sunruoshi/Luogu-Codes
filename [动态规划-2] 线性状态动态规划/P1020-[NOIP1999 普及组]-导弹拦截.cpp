#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 1e5 + 1;

int n, p1, p2, arr[MAXN], f1[MAXN], f2[MAXN];

int main() {
    while (~scanf("%d", &arr[++n]));
    fill(f1, f1 + MAXN, 0x3f3f3f3f);
    for (int i = 1; i < n; i++) {
        if (arr[i] <= f1[p1]) f1[++p1] = arr[i];
        else f1[upper_bound(f1 + 1, f1 + p1 + 1, arr[i], greater<int>()) - f1] = arr[i];
        if (arr[i] > f2[p2]) f2[++p2] = arr[i];
        else f2[lower_bound(f2 + 1, f2 + p2 + 1, arr[i]) - f2] = arr[i];
    }
    printf("%d\n%d", p1, p2);
    return 0;
}
