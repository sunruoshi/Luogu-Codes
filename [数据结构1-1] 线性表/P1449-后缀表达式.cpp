#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 判断当前字符是否是数字
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    string s;
    // 声明一个栈用来计算后缀表达式
    stack<int> rpn;
    cin >> s;
    int i = 0;
    while (s[i] != '@') {
        // 如果当前字符是操作符
        if (!isDigit(s[i]) && s[i] != '.') {
            // 将栈顶的两个元素取出用于计算
            int num1 = rpn.top();
            rpn.pop();
            int num2 = rpn.top();
            rpn.pop();
            // 将计算结果入栈
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
            // 读完一个数字，就将这个数字入栈
            rpn.push(num);
        }
        i++;
    }
    cout << rpn.top();
    return 0;
}
