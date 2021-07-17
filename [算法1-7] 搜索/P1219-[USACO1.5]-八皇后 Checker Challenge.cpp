#include <bits/stdc++.h>
using namespace std;

int n, cnt, queen[13];

void dfs(int row, int col, int x1, int x2) {
    if (row == n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < n; i++) {
                printf("%d ", queen[i]);
            }
            printf("\n");
        }
        return;
    }
    int pos = ((1 << n) - 1) & (~(col | x1 | x2));
    while (pos) {
        int p = pos & (-pos);
        pos = pos & (pos - 1);
        int column = 1, t = p;
        while (!(t & 1)) {
            column++;
            t >>= 1;
        }
        queen[row] = column;
        dfs(row + 1, col | p, (x1 | p) >> 1, (x2 | p) << 1);
        queen[row] = 0;
    }
}

int main() {
    scanf("%d", &n);
    dfs(0, 0, 0, 0);
    printf("%d", cnt);
    return 0;
}
