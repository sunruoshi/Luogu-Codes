#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int freq[n + 1]; // Ƶ�����飬���ڼ�������
    for (int i = 1; i <= n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        freq[d]++;
    }
    // ��Ƶ������������ȡ��ֵ���
    for (int i = 1; i <= n; i++) {
        while (freq[i]) {
            cout << i << " ";
            freq[i]--;
        }
    }
    return 0;
}
