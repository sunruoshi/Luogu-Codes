#include <cstdio>

using namespace std;

int main() {
    int n, p;
    scanf("%d", &n);
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            p = i;
            break;
        }
    }
    printf("%d", n / p);
    return 0;
}
