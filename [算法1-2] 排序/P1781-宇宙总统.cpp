// P1781-������ͳ
// ˼·
// ������������ݷ�Χ�ܴ�100λ���֣������Բ�������������������
// ����ʹ���ַ������Ͷ����Ʊ�����Զ���һ���ȽϺ������Ƚ������ַ�
// ���Ĵ�С����������ֻ��Ҫ֪�����ֵ�����Բ�����Ҫ�����ڶ�����
// ������ͬʱά�����ֵ���ɡ�
// ����ʹ��������������������������˼�룬���Ǹ߾��ȼ����˼�롣

#include <iostream>
#include <string>
using namespace std;

bool isGreater(string s1, string s2) {
    // ������������ȣ�λ������ͬ����Ӹ�λ����λ��λ�Ƚ�
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                return s1[i] - '0' > s2[i] - '0';
            }
        }
    } else {
        // ����λ���������һ����
        return s1.length() > s2.length();
    }
}

int main() {
    int n, id;
    string max_t = "0";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // �����ǰ���ִ���max�������max��id
        if (isGreater(s, max_t)) {
            max_t = s;
            id = i + 1;
        }
    }
    cout << id << endl << max_t;
    return 0;
}
