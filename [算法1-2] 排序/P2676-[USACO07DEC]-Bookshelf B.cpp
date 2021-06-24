// 解题思路
// 题目要求奶牛数量尽量少，按照贪心的思想，可以
// 将奶牛按身高从高到低依次累加，直到高度超过
// 书架的高度，即可得出答案。

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
    sort(cows, cows + n); // 将奶牛按身高排序
    i = n - 1;
    while (s < b) {
        s += cows[i--]; // 按身高从高到低累加
    }
    cout << n - i - 1;
    return 0;
}
