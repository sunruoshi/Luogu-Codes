#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q; // 构造一个队列q
    for (int i = 1; i <= n; i++) {
        q.push(i); // 将人的编号依次入队
    }
    while (q.size()) { // 一直循环直到队列为空
        for (int i = 1; i < m; i++) {
            q.push(q.front()); // 模拟将队首的人移到队尾
            q.pop();
        }
        cout << q.front() << " "; // 此时的队首为第M个人
        q.pop(); // 将此人出队
    }
    return 0;
}
