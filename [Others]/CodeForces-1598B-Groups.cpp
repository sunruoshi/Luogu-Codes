#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mat[n][5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        bool flag = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int x = 0, y = 0, z = 0;
                for (int k = 0; k < n; k++) {
                    x += mat[k][i];
                    y += mat[k][j];
                    z += mat[k][i] && mat[k][j];
                }
                x -= z;
                y -= z;
                if (max(0, n / 2 - x) + max(0, n / 2 - y) <= z) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}
