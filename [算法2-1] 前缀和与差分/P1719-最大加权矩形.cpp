#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sum[n + 1][n + 1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            scanf("%d", &val);
            sum[i][j] = sum[i - 1][j] + val;
        }
    }
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int temp = 0;
            for (int k = 1; k <= n; k++) {
                temp = max(temp, 0);
                temp += sum[i][k] - sum[j][k];
                ans = max(ans, temp);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
