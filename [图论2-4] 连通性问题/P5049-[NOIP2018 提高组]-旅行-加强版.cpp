#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 500001
using namespace std;

int n, m, tag, latest;
int dfn[MAXN], fa[MAXN];
bool loop[MAXN], visited[MAXN], flag;
vector<int> adj[MAXN];

void findLoop(int u) {
    dfn[u] = ++tag;
    for (int v : adj[u]) {
        if (v == fa[u]) continue;
        if (dfn[v]) {
            if (dfn[v] < dfn[u]) continue;
            loop[v] = 1;
            while (v != u) {
                loop[v = fa[v]] = 1;
            }
        } else {
            fa[v] = u;
            findLoop(v);
        }
    }
}

void dfs(int u) {
    if (visited[u]) return;
    printf("%d ", u);
    visited[u] = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int v : adj[u]) {
        if (!visited[v]) q.push(v);
    }
    while (q.size()) {
        if (!loop[u] || !loop[q.top()]) {
            dfs(q.top());
            q.pop();
        } else {
            if (q.size() > 1) {
                int v = q.top();
                q.pop();
                latest = q.top();
                dfs(v);
            } else {
                if (latest < q.top() && !flag) {
                    flag = 1;
                    return;
                } else {
                    dfs(q.top());
                    q.pop();
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findLoop(1);
    dfs(1);
    return 0;
}
