#include <cstdio>

int main() {
    int x, y, z, n;
    scanf("%d %d %d\n%d", &x, &y, &z, &n);
    int cube[x + 1][y + 1][z + 1], cnt = x * y * z;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 1; k <= z; ++k) {
                cube[i][j][k] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int x1, y1, z1, x2, y2, z2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int j = x1; j <= x2; ++j) {
            for (int k = y1; k <= y2; ++k) {
                for (int l = z1; l <= z2; ++l) {
                    if (cube[j][k][l] == 1) {
                        cube[j][k][l] = 0;
                        cnt--;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
