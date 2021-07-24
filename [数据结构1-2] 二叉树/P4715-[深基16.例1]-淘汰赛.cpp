#include <cstdio>
using namespace std;

const int MAXN = 1 << 8;

int n, val[MAXN], win[MAXN];

void dfs(int root) {
    if (root >= (1 << n)) return;
    int left = 2 * root, right = 2 * root + 1;
    dfs(left);
    dfs(right);
    if (val[left] > val[right]) {
        val[root] = val[left];
        win[root] = win[left];
    } else {
        val[root] = val[right];
        win[root] = win[right];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", &val[i + (1 << n)]);
        win[i + (1 << n)] = i + 1;
    }
    dfs(1);
    printf("%d", val[2] > val[3] ? win[3] : win[2]);
    return 0;
}
