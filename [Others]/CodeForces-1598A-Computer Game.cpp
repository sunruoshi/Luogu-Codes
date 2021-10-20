#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int MAXN = 100;

int n, t;
string maze[2];
bool vis[2][MAXN];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (auto dir : dirs) {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && nx < 2 && ny >= 0 && ny < n && !vis[nx][ny] && maze[nx][ny] == '0') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        cin >> maze[0] >> maze[1];
        dfs(0, 0);
        if (vis[1][n - 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
