// P1996-Լɪ������ ģ�ⷨ
// ˼·
// ʹ�������±���Ϊ��ţ�ֵ��������Ƿ����
// ʹ��һ������cnt����ǵ�ǰ���������֣���cnt==mʱ����ǰλ�õ�����Ҫ����
// ʹ��һ������total���������������˶�����ʱ�˳�ѭ��
#include <iostream>
using namespace std;

int main() {
    int n, m, p = 0, total = 0, cnt = 0; // pָ���ǵ�ǰ��������
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        a[i] = 0; // �����ʼ��Ϊ0��0�����ڶ���
    }
    while (total < n) {
        if (a[p % (n + 1)] == 0) {
            cnt++;
            if (cnt == m) {
                cout << p % (n + 1) << ' ';
                a[p % (n + 1)] = 1;
                cnt = 0;
                total++;
            }
        }
        p++;
    }
    return 0;
}
