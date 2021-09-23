#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    private:
        vector<int> fa, dis, size;

    public:
        UnionFind(int n) {
            fa.resize(n + 1);
            dis.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
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
        int Dis(int x, int y) {
            return abs(dis[x] - dis[y]) - 1;
        }
};

int main() {
    int n;
    cin >> n;
    UnionFind uf(n);
    while (n--) {
        char opt;
        int i, j;
        cin >> opt >> i >> j;
        if (opt == 'M') uf.Union(i, j);
        else {
            if (uf.Find(i) != uf.Find(j)) cout << "-1" << endl;
            else cout << uf.Dis(i, j) << endl;
        }
    }
    return 0;
}
