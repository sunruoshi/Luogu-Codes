#include <cstdio>
#include <cmath>
using namespace std;

int n, pos, arr[31];

int main() {
    scanf("%d", &n);
    if (n & 1) {
        printf("-1");
        return 0;
    }
    while (n) {
        if (n & 1) arr[pos] = pow(2, pos);
        n >>= 1;
        pos++;
    }
    for (int i = pos; i >= 0; i--) {
        if (arr[i]) printf("%d ", arr[i]);
    }
    return 0;
}
