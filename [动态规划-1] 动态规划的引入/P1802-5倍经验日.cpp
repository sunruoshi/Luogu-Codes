// P1802 5��������
#include <cstdio>
#include <algorithm>
using namespace std;

long long lose[1000], win[1000], use[1000], dp[1001]; // �������ݷ�Χ��Ӧ��ʹ��long long����

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%ld %ld %ld", &lose[i], &win[i], &use[i]); // ��������
    }
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            // ״̬ת�Ʒ���
            if (j >= use[i]) dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
            else dp[j] += lose[i];
        }
    }
    printf("%ld", 5 * dp[x]); // 5������
    return 0;
}
