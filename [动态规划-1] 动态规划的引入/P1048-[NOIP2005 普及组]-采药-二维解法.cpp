// P1048 ��ҩ ��άDP����ⷨ
#include <cstdio>
#include <algorithm>
using namespace std;

int w[101], c[101], dp[101][1001];

int main() {
    int t, m; // tΪ��������
    scanf("%d %d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &w[i], &c[i]); // ����ÿ�ֲ�ҩ��ժ��Ҫ��ʱ��Ͳ�ҩ�ļ�ֵ
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= t; j++) {
            // ״̬ת�Ʒ���
            if (w[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[m][t]); // dp[m][t]��Ϊ��
    return 0;
}
