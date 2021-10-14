#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    int sum[n + 1][m + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int val;
            scanf("%d", &val);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val;
        }
    }
    int ans = -INF, x, y;
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            int temp = 
                sum[i + c - 1][j + c - 1] + 
                sum[i - 1][j - 1] - 
                sum[i - 1][j + c - 1] - 
                sum[i + c - 1][j - 1];
            if (temp > ans) {
                ans = temp;
                x = i;
                y = j;
            }
        }
    }
    printf("%d %d", x, y);
    return 0;
}
