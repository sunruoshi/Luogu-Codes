#include <cstdio>
#include <string>
using namespace std;

const string WORD = "yizhong";

int n, dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char mat[100][100];
bool check[100][100];

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        bool flag = 1;
        for (int pos = 1; pos < 7; pos++) {
            int nx = x + pos * dirs[i][0], ny = y + pos * dirs[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || mat[nx][ny] != WORD[pos]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int pos = 0; pos < 7; pos++) {
                int nx = x + pos * dirs[i][0], ny = y + pos * dirs[i][1];
                check[nx][ny] = 1;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", mat[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'y') dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j]) printf("%c", mat[i][j]);
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}
