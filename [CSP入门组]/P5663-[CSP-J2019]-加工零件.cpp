#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100001, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
    Node(int _v, int _dis) : v(_v), dis(_dis) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

int n, m, t, dis[MAXN][2];
vector<int> adj[MAXN];
bool visited[MAXN][2];

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dis[0], dis[0] + MAXN * 2, INF);
    priority_queue<Node> q;
    dis[1][0] = 0;
    q.push(Node(1, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        for (int v : adj[u]) {
            if (dis[u][1] + 1 < dis[v][0]) {
                dis[v][0] = dis[u][1] + 1;
                if (!visited[v][0]) {
                    visited[v][0] = 1;
                    q.push(Node(v, dis[v][0]));
                }
            }
            if (dis[u][0] + 1 < dis[v][1]) {
                dis[v][1] = dis[u][0] + 1;
                if (!visited[v][1]) {
                    visited[v][1] = 1;
                    q.push(Node(v, dis[v][1]));
                }
            }
        }
    }
    while (t--) {
        int a, L;
        scanf("%d %d", &a, &L);
        if (dis[a][L % 2] <= L) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
