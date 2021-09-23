#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 200001, INF = 0x3f3f3f3f;

int n, ans = INF, in[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int s, int len) {
    in[u]--;
    for (int v : adj[u]) {
        if (v == s) {
            ans = min(ans, len);
            return;
        }
        dfs(v, s, len + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int u = 1; u <= n; u++) {
        int v;
        scanf("%d", &v);
        adj[u].push_back(v);
        in[v]++;
    }
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push_back(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push_back(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i]) dfs(i, i, 1);
    }
    printf("%d", ans);
    return 0;
}
