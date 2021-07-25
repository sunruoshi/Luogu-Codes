#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN], inq[MAXN];

void dfs(int u) {
    printf("%d ", u);
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v);
    }
}

void bfs(int u) {
    deque<int> q;
    q.push_back(u);
    inq[u] = 1;
    while (q.size()) {
        int cur = q.front();
        q.pop_front();
        printf("%d ", cur);
        for (int i = 0; i < adj[cur].size(); i++) {
            int v = adj[cur][i];
            if (!inq[v]) {
                q.push_back(v);
                inq[v] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(1);
    printf("\n");
    bfs(1);
    return 0;
}
