// ����˼·
// ��ĿҪ����ţ���������٣�����̰�ĵ�˼�룬����
// ����ţ����ߴӸߵ��������ۼӣ�ֱ���߶ȳ���
// ��ܵĸ߶ȣ����ɵó��𰸡�

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, i;
    long long b, s = 0;
    cin >> n >> b;
    long long cows[n];
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows + n); // ����ţ���������
    i = n - 1;
    while (s < b) {
        s += cows[i--]; // ����ߴӸߵ����ۼ�
    }
    cout << n - i - 1;
    return 0;
}
