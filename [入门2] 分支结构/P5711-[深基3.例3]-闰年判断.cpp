// 闰年判断：
// 1. 能被4整除但不能被100整除
// 2. 能被400整除

#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n % 4 == 0 && n % 100 != 0 || n % 400 == 0);
    return 0;
}
