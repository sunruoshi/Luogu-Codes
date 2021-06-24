#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// �ȽϺ���
bool cmp(string s1, string s2) {
    int i = 0;
    // �����������û�ж��꣬��Ӹ�λ����λ���αȽ�
    while (i < s1.length() && i < s2.length()) {
        if (s1[i] - '0' != s2[i] - '0') return s1[i] - '0' > s2[i] - '0';
        i++;
    }
    // ���һ������������һ������û�ж��꣬��ݹ�ıȽϽ϶̵����ͽϳ�����ʣ�ಿ��
    return s1.length() < s2.length() ? cmp(s1, s2.substr(i)) : cmp(s1.substr(i), s2);
}

int main() {
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    return 0;
}
