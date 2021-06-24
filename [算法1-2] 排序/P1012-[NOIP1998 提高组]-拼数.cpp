#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 比较函数
bool cmp(string s1, string s2) {
    int i = 0;
    // 如果两个数都没有读完，则从高位往低位依次比较
    while (i < s1.length() && i < s2.length()) {
        if (s1[i] - '0' != s2[i] - '0') return s1[i] - '0' > s2[i] - '0';
        i++;
    }
    // 如果一个数读完了另一个数还没有读完，则递归的比较较短的数和较长数的剩余部分
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
