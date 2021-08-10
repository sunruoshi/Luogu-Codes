#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 1501, INF = 0x3f3f3f3f;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, dp[MAXN], in[MAXN];
vector<Edge> adj[MAXN];
bool valid[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    fill(dp, dp + MAXN, -INF);
    dp[n] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[v].push_back(Edge(u, w));
        in[u]++;
    }
    deque<int> q;
    q.push_back(n);
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (Edge edge : adj[u]) {
            int v = edge.v;
            if (valid[v]) continue;
            valid[v] = 1;
            q.push_back(v);
        }
    }
    if (!valid[1]) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push_back(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (Edge edge : adj[u]) {
            int v = edge.v, w = edge.w;
            dp[v] = max(dp[v], dp[u] + w);
            in[v]--;
            if (!in[v]) q.push_back(v);
        }
    }
    printf("%d", dp[1]);
    return 0;
}
