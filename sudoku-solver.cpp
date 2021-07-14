#include <bits/stdc++.h>
using namespace std;

int pos, sudoku[9][9], spaces[81][2];
bool valid, row[9][10], col[9][10], block[3][3][10];

void dfs(int cur) {
    if (cur == pos) {
        valid = 1;
        return;
    }
    int i = spaces[cur][0], j = spaces[cur][1];
    for (int digit = 1; digit <= 9 && !valid; digit++) {
        if (!row[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit]) {
            row[i][digit] = 1;
            col[j][digit] = 1;
            block[i / 3][j / 3][digit] = 1;
            sudoku[i][j] = digit;
            dfs(cur + 1);
            row[i][digit] = 0;
            col[j][digit] = 0;
            block[i / 3][j / 3][digit] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j] == 0) {
                spaces[pos][0] = i;
                spaces[pos][1] = j;
                pos++;
            } else {
                row[i][sudoku[i][j]] = 1;
                col[j][sudoku[i][j]] = 1;
                block[i / 3][j / 3][sudoku[i][j]] = 1;
            }
        }
    }
    dfs(0);
    if (valid) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No Answer!\n");
    }
    return 0;
}
