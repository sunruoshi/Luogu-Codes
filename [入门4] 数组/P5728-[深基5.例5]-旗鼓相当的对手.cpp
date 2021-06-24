#include <cstdio>
#include <stdlib.h>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    int stu[n][3];
    for (int i = 0; i < n; ++i) scanf("%d %d %d", &stu[i][0], &stu[i][1], &stu[i][2]);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(stu[i][0] + stu[i][1] + stu[i][2] - stu[j][0] - stu[j][1] - stu[j][2]) <= 10 &&
                abs(stu[i][0] - stu[j][0]) <= 5 &&
                abs(stu[i][1] - stu[j][1]) <= 5 &&
                abs(stu[i][2] - stu[j][2]) <= 5)
                cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
