#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200001, INF = 0x3f3f3f;

int n, ans = INF, fa[MAXN], dis[MAXN];

int Find(int x) {
    if (x != fa[x]) {
        int temp = fa[x];
        fa[x] = Find(fa[x]);
        dis[x] += dis[temp];
    }
    return fa[x];
}

void Union(int x, int y) {
    int xx = Find(x), yy = Find(y);
    if (xx != yy) {
        fa[xx] = yy;
        dis[x] = dis[y] + 1;
    } else {
        ans = min(ans, dis[x] + dis[y] + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int x = 1; x <= n; x++) {
        int y;
        scanf("%d", &y);
        Union(x, y);
    }
    printf("%d", ans);
    return 0;
}
