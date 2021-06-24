#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int t;
};

int m, farm[302][302], visited[302][302], dirs[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    memset(farm, -1, sizeof(farm));
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        for (int j = 0; j < 5; j++) {
            int nx = x + dirs[j][0], ny = y + dirs[j][1];
            if (nx >= 0 && ny >= 0 && (farm[nx][ny] == -1 || farm[nx][ny] > t)) {
                farm[nx][ny] = t;
            }
        }
    }
    queue<node> q;
    q.push(node({0, 0, 0}));
    while (q.size()) {
        node cur = q.front();
        if (farm[cur.x][cur.y] == -1) {
            printf("%d", cur.t);
            return 0;
        }
        q.pop();
        for (int i = 1; i < 5; i++) {
            int nx = cur.x + dirs[i][0], ny = cur.y + dirs[i][1];
            if (nx >= 0 && ny >= 0 && (cur.t + 1 < farm[nx][ny] || farm[nx][ny] == -1) && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push(node({nx, ny, cur.t + 1}));
            }
        }
    }
    printf("-1");
    return 0;
}
