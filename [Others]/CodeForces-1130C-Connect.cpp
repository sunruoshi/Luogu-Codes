#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, r1, c1, r2, c2;
string g[50];
bool vis[50][50];

void dfs(Node p, vector<Node> &a) {
    a.push_back(p);
    vis[p.x][p.y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = p.x + DIRS[i][0], ny = p.y + DIRS[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && g[nx][ny] == '0') {
            dfs(Node(nx, ny), a);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    vector<Node> v1, v2;
    dfs(Node(r1 - 1, c1 - 1), v1);
    memset(vis, 0, sizeof(vis));
    dfs(Node(r2 - 1, c2 - 1), v2);
    int ans = 0x3f3f3f3f;
    auto dist = [&](Node a, Node b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    };
    for (auto p1: v1) {
        for (auto p2 : v2) {
            ans = min(ans, dist(p1, p2));
        }
    }
    cout << ans;
    return 0;
}
