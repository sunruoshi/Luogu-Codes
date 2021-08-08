#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 30001;

int n, dis[MAXN];

struct UnionFind {
    int fa[MAXN], size[MAXN];
    UnionFind() {
        for (int i = 1; i < MAXN; i++) {
            fa[i] = i;
            size[i] = 1;
        }
    }
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
        dis[xx] += size[yy];
        size[yy] += size[xx];
        size[xx] = 0;
        fa[xx] = yy;
    }
};

int main() {
    cin >> n;
    UnionFind uf;
    while (n--) {
        char opt;
        int i, j;
        cin >> opt >> i >> j;
        if (opt == 'M') uf.Union(i, j);
        else {
            if (uf.Find(i) != uf.Find(j)) cout << "-1" << endl;
            else cout << abs(dis[i] - dis[j]) - 1 << endl;
        }
    }
    return 0;
}
