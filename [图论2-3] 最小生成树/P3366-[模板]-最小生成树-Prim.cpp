#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 5001, INF = 0x3f3f3f3f;

struct Vert {
    int id, dis;
    Vert(int x, int y) : id(x), dis(y) {}
    bool operator < (const Vert &a) const {
        return dis > a.dis;
    }
};

int n, m, cnt, ans, dis[N];
vector<pair<int, int>> adj[N];
bool vis[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // Prim
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    priority_queue<Vert> pq;
    pq.push(Vert(1, 0));
    while (pq.size()) {
        int u = pq.top().id;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += dis[u];
        cnt++;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (!vis[v] && w < dis[v]) {
                dis[v] = w;
                pq.push(Vert(v, dis[v]));
            }
        }
    }
    if (cnt == n) cout << ans; // form a MST
    else cout << "orz";
    return 0;
}
