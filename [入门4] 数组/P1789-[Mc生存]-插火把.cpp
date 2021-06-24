#include <cstdio>
#include <cmath>

int main() {
    int n, m, k, cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    int mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        // 注意这里x，y的坐标是从1开始的
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j = x - 3; j <= x + 1; ++j) {
            for (int l = y - 3; l <= y + 1; ++l) {
                if (j >= 0 && j < n && l >= 0 && l < n && abs(j - x + 1) + abs(l - y + 1) <= 2 && mat[j][l] == 0)
                    mat[j][l]++;
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j = x - 3; j <= x + 1; ++j) {
            for (int l = y - 3; l <= y + 1; ++l) {
                if (j >= 0 && j < n && l >= 0 && l < n && mat[j][l] == 0) mat[j][l]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
