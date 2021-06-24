#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, q, op, i, j, k; // op���������1Ϊ�����2Ϊ��ѯ
    scanf("%d%d", &n, &q);
    vector<vector<int> > locker (n + 1);
    while (q--) {
        scanf("%d%d%d", &op, &i, &j);
        if (op == 1) {
            scanf("%d", &k);
            // ���vector��С��������ʹ��resize�������ı��С
            if (locker[i].size() < j + 1) locker[i].resize(j + 1);
            locker[i][j] = k;
        } else {
            printf("%d\n", locker[i][j]);
        }
    }
    return 0;
}
