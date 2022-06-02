#include <iostream>
#include <cstring>
using namespace std;

const int N = 51;

int n, m, dis[N][N];
bool check[N][N][65];

int main() {
    cin.sync_with_stdio(0);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dis[u][v] = 1;
        check[u][v][0] = 1;
    }
    for (int x = 1; x <= 64; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (check[i][j][x - 1] && check[j][k][x - 1]) {
                        check[i][k][x] = 1;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << dis[1][n];
    return 0;
}
