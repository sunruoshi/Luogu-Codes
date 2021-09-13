#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 5001
using namespace std;

int n, m, tag, top, latest;
int dfn[MAXN], low[MAXN], stk[MAXN];
bool inStack[MAXN], circle[MAXN], visited[MAXN], flag;
vector<int> adj[MAXN];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tag;
    stk[++top] = u;
    int pos = top;
    inStack[u] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        if (pos == top) inStack[stk[top--]] = 0;
        while (pos <= top) {
            circle[stk[top]] = 1;
            inStack[stk[top]] = 0;
            top--;
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
        if (!circle[u] || !circle[q.top()]) {
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
    tarjan(1, 0);
    dfs(1);
    return 0;
}
