#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 5000, INF = 0x3f3f3f3f;

struct Node {
    int v, dis;
    Node(int a, int b) : v(a), dis(b) {}
    bool operator < (const Node &a) const {
        return dis > a.dis;
    }
};

struct Edge {
    int v, w;
    Edge() {}
    Edge(int a, int b) : v(a), w(b) {}
};

int n, m, cnt, ans, dis[MAXN + 1];
vector<Edge> adj[MAXN + 1];
bool vis[MAXN + 1];

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }
    // Prim
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    priority_queue<Node> pq;
    pq.push(Node(1, 0));
    while (pq.size()) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += dis[u];
        cnt++;
        for (auto e : adj[u]) {
            int v = e.v, w = e.w;
            if (!vis[v] && w < dis[v]) {
                dis[v] = w;
                pq.push(Node(v, dis[v]));
            }
        }
    }
    if (cnt == n) cout << ans; // form a MST
    else cout << "orz";
    return 0;
}
