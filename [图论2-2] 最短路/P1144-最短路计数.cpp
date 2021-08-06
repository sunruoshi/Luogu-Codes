#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1000001, INF = 0x3f3f3f3f, MOD = 100003;

struct Node {
    int v, dis;
    Node(int _v, int _dis) {
        v = _v, dis = _dis;
    }
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

int n, m, dis[MAXN], num[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dis, dis + MAXN, INF);
    dis[1] = 0;
    num[1] = 1;
    priority_queue<Node> q;
    q.push(Node(1, 0));
    while (q.size()) {
        int u = q.top().v;
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (unsigned int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (visited[v]) continue;
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                num[v] = num[u];
                q.push(Node(v, dis[v]));
            } else if (dis[u] + 1 == dis[v]) {
                num[v] = (num[v] % MOD + num[u] % MOD) % MOD; 
            }
        }
    }
    for (int i = 1; i<= n; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}
