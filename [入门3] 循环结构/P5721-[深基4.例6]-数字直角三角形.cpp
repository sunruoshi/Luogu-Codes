#include <cstdio>

using namespace std;

int main() {
    int n, c, d = 1;
    scanf("%d", &n);
    c = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            printf("%02d", d++);
        }
        c--;
        printf("\n");
    }
    return 0;
}
