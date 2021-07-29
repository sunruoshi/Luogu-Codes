#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, ans, in[MAXN], dp[MAXN], len[MAXN];
vector<int> adj[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d %d", &u, &len[i]);
        while (1) {
            int pre;
            scanf("%d", &pre);
            if (!pre) break;
            adj[pre].push_back(u);
            in[u]++;
        }
    }
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push_back(i);
            dp[i] = len[i];
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            dp[v] = max(dp[v], dp[u] + len[v]);
            in[v]--;
            if (!in[v]) q.push_back(v);
        }
        ans = max(ans, dp[u]);
    }
    printf("%d", ans);
    return 0;
}
