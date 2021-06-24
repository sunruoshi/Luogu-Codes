// P1781-宇宙总统
// 思路
// 这个题由于数据范围很大（100位数字），所以不能用数字类型来处理。
// 考虑使用字符串类型读入得票数，自定义一个比较函数来比较数字字符
// 串的大小。由于我们只需要知道最大值，所以不并需要排序，在读入字
// 符串的同时维护最大值即可。
// 这种使用其他数据类型来处理超大数的思想，就是高精度计算的思想。

#include <iostream>
#include <string>
using namespace std;

bool isGreater(string s1, string s2) {
    // 如果两个数长度（位数）相同，则从高位到低位逐位比较
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                return s1[i] - '0' > s2[i] - '0';
            }
        }
    } else {
        // 否则，位数多的数字一定大
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
        // 如果当前数字大于max，则更新max和id
        if (isGreater(s, max_t)) {
            max_t = s;
            id = i + 1;
        }
    }
    cout << id << endl << max_t;
    return 0;
}
