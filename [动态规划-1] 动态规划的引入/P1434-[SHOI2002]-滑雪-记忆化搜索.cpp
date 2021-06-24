#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, ans, m[100][100], temp[100][100], dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int x, int y) {
    if (temp[x][y]) return temp[x][y];
    temp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && m[nx][ny] < m[x][y]) {
            temp[x][y] = max(temp[x][y], dfs(nx, ny) + 1);
        }
    }
    return temp[x][y];
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    printf("%d", ans);
    return 0;
}
