#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, q, op, i, j, k; // op代表操作，1为存包，2为查询
    scanf("%d%d", &n, &q);
    vector<vector<int> > locker (n + 1);
    while (q--) {
        scanf("%d%d%d", &op, &i, &j);
        if (op == 1) {
            scanf("%d", &k);
            // 如果vector大小不够，则使用resize方法来改变大小
            if (locker[i].size() < j + 1) locker[i].resize(j + 1);
            locker[i][j] = k;
        } else {
            printf("%d\n", locker[i][j]);
        }
    }
    return 0;
}
