#include <iostream>
using namespace std;

int n, m, ans, dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char field[100][100];

void dfs(int x, int y) {
    field[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
