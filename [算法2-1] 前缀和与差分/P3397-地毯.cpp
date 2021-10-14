#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int g[n + 2][n + 2], flag[n + 2][n + 2];
    memset(g, 0, sizeof(g));
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1; j <= x2; j++) {
            flag[j][y1]++;
            flag[j][y2 + 1]--;
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        int sum = 0;
        for (int j = 1; j <= n + 1; j++) {
            sum += flag[i][j];
            g[i][j] = sum;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
