#include <cstdio>

using namespace std;

int main() {
    int n, min = 1000, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (d < min) min = d;
        if (d > max) max = d;
    }
    printf("%d", max - min);
    return 0;
}
