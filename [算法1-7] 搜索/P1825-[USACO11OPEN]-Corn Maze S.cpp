#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int step;
};

int n, m, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char maze[301][301];
bool visited[301][301], letter[26];
node gate[26][2], start;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                start.x = i;
                start.y = j;
            } else if (maze[i][j] >= 'A' && maze[i][j] <= 'Z') {
                int k = maze[i][j] - 'A';
                if (!letter[k]) {
                    letter[k] = 1;
                    gate[k][0].x = i;
                    gate[k][0].y = j;
                } else {
                    gate[k][1].x = i;
                    gate[k][1].y = j;
                }
            }
        }
    }
    queue<node> q;
    q.push(start);
    while (q.size()) {
        node cur = q.front();
        q.pop();
        if (maze[cur.x][cur.y] == '=') {
            cout << cur.step;
            return 0;
        }
        if (maze[cur.x][cur.y] >= 'A' && maze[cur.x][cur.y] <= 'Z') {
            int k = maze[cur.x][cur.y] - 'A';
            if (cur.x == gate[k][0].x && cur.y == gate[k][0].y) {
                cur.x = gate[k][1].x;
                cur.y = gate[k][1].y;
            } else {
                cur.x = gate[k][0].x;
                cur.y = gate[k][0].y;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dirs[i][0], ny = cur.y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push(node({nx, ny, cur.step + 1}));
            }
        }
    }
    return 0;
}
