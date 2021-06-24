#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, max1 = 0, max2 = 0, max3 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (d == max1 || d == max2 || d == max3) continue;
        if (d > max1) {
            max3 = max2;
            max2 = max1;
            max1 = d;
        } else if (d > max2) {
            max3 = max2;
            max2 = d;
        } else if (d > max3) {
            max3 = d;
        }
    }
    if (n == 2) printf("%d", max2);
    else if (n == 1 || max3 == max2 && max2 == max1) printf("-1");
    else printf("%d", max(max3, max1 % max2));
    return 0;
}
