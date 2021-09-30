#include <cstdio>
#include <cstdlib>

class BinaryIndexedTree {
    private:
        int* c;
        size_t len;

    public:
        BinaryIndexedTree(int n) : len(n) {
            c = (int*) malloc(n * sizeof(int));
        }
        int query(size_t pos) {
            int res = 0;
            while (pos < len) {
                res += c[pos];
                pos += pos & (-pos);
            }
            return res;
        }
        void update(size_t pos, int v) {
            while (pos > 0) {
                c[pos] += v;
                pos -= pos & (-pos);
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
