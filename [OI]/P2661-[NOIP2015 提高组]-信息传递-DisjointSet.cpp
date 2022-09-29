#include <iostream>
using namespace std;

const int N = 2e5 + 1, INF = 0x3f3f3f3f;

int n, ans = INF, fa[N], dis[N];

void init() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}

int query(int x) {
    if (x != fa[x]) {
        int temp = fa[x];
        fa[x] = query(fa[x]);
        dis[x] += dis[temp];
    }
    return fa[x];
}

void merge(int x, int y) {
    int xx = query(x), yy = query(y);
    if (xx != yy) {
        fa[xx] = yy;
        dis[x] = dis[y] + 1;
    } else {
        ans = min(ans, dis[x] + dis[y] + 1);
    }
}

int main() {
    cin >> n;
    init();
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        merge(u, v);
    }
    cout << ans << endl;
    return 0;
}
