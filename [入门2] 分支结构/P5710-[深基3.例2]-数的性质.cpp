#include <cstdio>

using namespace std;

int main() {
    int n, a, b, c, d;
    bool one, two; //性质1 性质2
    scanf("%d", &n);
    one = n % 2 == 0; // 性质1：是偶数
    two = n > 4 && n <= 12; // 性质2：大于 4 且不大于 12
    a = one && two ? 1 : 0;
    b = one || two ? 1 : 0;
    c = (one && !two) || (!one && two) ? 1 : 0;
    d = !one && !two ? 1 : 0;
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}
