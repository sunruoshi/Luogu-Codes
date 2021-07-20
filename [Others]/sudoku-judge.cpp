#include <cstdio>

bool row[9][10], col[9][10], block[3][3][10];

int main() {
    int board[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
            if (row[i][board[i][j]] || col[j][board[i][j]] || block[i / 3][j / 3][board[i][j]]) {
                printf("No\n");
                return 0;
            }
            row[i][board[i][j]] = 1;
            col[j][board[i][j]] = 1;
            block[i / 3][j / 3][board[i][j]] = 1;
        }
    }
    printf("Yes\n");
    return 0;
}
