#include <cstdio>

using namespace std;

int main() {
    int n, x, k = 1;
    scanf("%d", &n);
    // 由于K上限未知，此处为无限循环
    // k从最小值开始遍历，一旦满足题意，就可以直接return
    while (true) {
        for (x = 100; x > 0; x--)
            if ((7 * x + 21 * k) * 52 == n) {
                printf("%d\n%d\n", x, k);
                return 0;
            }
        k++;
    }
}
