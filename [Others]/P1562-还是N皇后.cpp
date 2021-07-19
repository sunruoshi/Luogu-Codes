#include <cstdio>
using namespace std;

int n, cnt;
char board[14][14];

void dfs(int row, int col, int x1, int x2) {
    if (row == n) {
        cnt++;
        return;
    }
    int pos = ((1 << n) - 1) & (~(col | x1 | x2));
    while (pos) {
        int p = pos & (-pos);
        pos = pos & (pos - 1);
        int column = 0, t = p;
        while (!(t & 1)) {
            column++;
            t >>= 1;
        }
        if (board[row][column] != '.') {
            dfs(row + 1, col | p, (x1 | p) >> 1, (x2 | p) << 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }
    dfs(0, 0, 0, 0);
    printf("%d", cnt);
    return 0;
}
