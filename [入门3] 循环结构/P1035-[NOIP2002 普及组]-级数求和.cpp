/*
 * 思路：模拟
 * 注意浮点数精度。最好使用double
 */

#include<cstdio>

using namespace std;

int main() {
    double sn = 0.0, k;
    int n = 0;
    scanf("%lf", &k);
    while (sn <= k)
        sn += 1.0 / ++n;
    printf("%d", n);
    return 0;
}
