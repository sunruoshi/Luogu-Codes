#include <cstdio>
#include <vector>
#define lowbit(i) ((i) & (-i))
using namespace std;

class BinaryIndexedTree {
private:
    vector<int> c;

public:
    BinaryIndexedTree(int n) {
        c.resize(n, 0);
    }
    int query(unsigned pos) {
        int res = 0;
        while (pos < c.size()) {
            res += c[pos];
            pos += lowbit(pos);
        }
        return res;
    }
    void update(int pos, int v) {
        while (pos > 0) {
            c[pos] += v;
            pos -= lowbit(pos);
        }
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    BinaryIndexedTree bit(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        bit.update(i, x);
        bit.update(i - 1, -x);
    }
    for (int i = 1; i <= m; i++) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            bit.update(y, k);
            bit.update(x - 1, -k);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", bit.query(x));
        }
    }
    return 0;
}
