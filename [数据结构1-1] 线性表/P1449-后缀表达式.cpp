#include <iostream>
#include <string>
#include <stack>
using namespace std;

// �жϵ�ǰ�ַ��Ƿ�������
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    string s;
    // ����һ��ջ���������׺���ʽ
    stack<int> rpn;
    cin >> s;
    int i = 0;
    while (s[i] != '@') {
        // �����ǰ�ַ��ǲ�����
        if (!isDigit(s[i]) && s[i] != '.') {
            // ��ջ��������Ԫ��ȡ�����ڼ���
            int num1 = rpn.top();
            rpn.pop();
            int num2 = rpn.top();
            rpn.pop();
            // ����������ջ
            if (s[i] == '+') rpn.push(num2 + num1);
            else if (s[i] == '-') rpn.push(num2 - num1);
            else if (s[i] == '*') rpn.push(num2 * num1);
            else if (s[i] == '/') rpn.push(num2 / num1);
        } else if (isDigit(s[i])) {
            int num = 0;
            while (isDigit(s[i])) {
                num *= 10;
                num += s[i++] - '0';
            }
            // ����һ�����֣��ͽ����������ջ
            rpn.push(num);
        }
        i++;
    }
    cout << rpn.top();
    return 0;
}
