#include <iostream>
using namespace std;

int n, m, t, ans, sx, sy, fx, fy, mat[6][6], dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    mat[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !mat[nx][ny]) {
            dfs(nx, ny);
            mat[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        mat[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans;
    return 0;
}
