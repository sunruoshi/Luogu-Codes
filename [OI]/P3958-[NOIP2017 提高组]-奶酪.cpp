#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    private:
        int* fa;

    public:
        UnionFind(int n) {
            fa = (int*) malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
        }
        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }
        void Union(int x, int y) {
            fa[Find(x)] = Find(y);
        }
};

struct Node {
    int x, y, z;
};

int main() {
    int t;
    scanf("%d", &t);
    auto dist = [&](Node a, Node b) {
        long long dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    };
    while (t--) {
        int n, h, r;
        scanf("%d %d %d", &n, &h, &r);
        UnionFind uf(n);
        Node node[n];
        vector<int> floorSide, ceilSide;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &node[i].x, &node[i].y, &node[i].z);
            if (node[i].z <= r) floorSide.push_back(i);
            if (node[i].z >= h - r) ceilSide.push_back(i);
            for (int j = 0; j < i; j++) {
                if (dist(node[i], node[j]) <= r << 1) {
                    uf.Union(i, j);
                }
            }
        }
        bool flag = 0;
        for (int i : floorSide) {
            for (int j : ceilSide) {
                if (uf.Find(i) == uf.Find(j)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
