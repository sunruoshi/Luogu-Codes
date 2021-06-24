// P1996-约瑟夫问题 模拟法
// 思路
// 使用数组下标作为编号，值用来标记是否出队
// 使用一个变量cnt来标记当前报到的数字，当cnt==m时，当前位置的人需要出队
// 使用一个变量total来计数，当所有人都出队时退出循环
#include <iostream>
using namespace std;

int main() {
    int n, m, p = 0, total = 0, cnt = 0; // p指针标记当前报数的人
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        a[i] = 0; // 数组初始化为0，0代表还在队中
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
