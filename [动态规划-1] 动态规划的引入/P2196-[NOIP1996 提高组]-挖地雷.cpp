#include <cstdio>
#include <vector>
using namespace std;

int n, start, ans, w[21], Next[21], dp[21];
vector<int> adj[21];

int DP(int u) {
    if (dp[u]) return dp[u];
    for (int v : adj[u]) {
        int temp = DP(v);
        if (temp > dp[u]) {
            dp[u] = temp;
            Next[u] = v;
        }
    }
    dp[u] += w[u];
    return dp[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t;
            scanf("%d", &t);
            if (t) adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = DP(i);
        if (dp[i] > ans) {
            ans = dp[i];
            start = i;
        }
    }
    while (start) {
        printf("%d ", start);
        start = Next[start];
    }
    printf("\n%d", ans);
    return 0;
}
