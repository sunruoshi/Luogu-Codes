#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    // r，c用来保存K-1的行，列坐标
    int cube[n][n], r = 0, c = n / 2;
    // 将矩阵初始化为0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cube[i][j] = 0;
    }
    // 将1放在第一行中间位置
    cube[r][c] = 1;
    for (int i = 2; i <= n * n; ++i) {
        // 根据题目条件，更新r，c的值
        if (r == 0 && c != n - 1) {
            r = n - 1;
            c += 1;
        } else if (r != 0 && c == n - 1) {
            r -= 1;
            c = 0;
        } else if (r == 0 && c == n - 1) {
            r += 1;
        } else if (r != 0 && c != n - 1) {
            if (cube[r - 1][c + 1] == 0) {
                r -= 1;
                c += 1;
            } else {
                r += 1;
            }
        }
        // 更新矩阵的值，此时行，列坐标已被更新
        // 下个循环时，r，c即为K-1的行，列坐标
        cube[r][c] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", cube[i][j]);
        // 每打完一行就换行输出
        printf("\n");
    }
    return 0;
}
