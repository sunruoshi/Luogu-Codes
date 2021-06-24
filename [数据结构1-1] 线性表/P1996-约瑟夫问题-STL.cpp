#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q; // ����һ������q
    for (int i = 1; i <= n; i++) {
        q.push(i); // ���˵ı���������
    }
    while (q.size()) { // һֱѭ��ֱ������Ϊ��
        for (int i = 1; i < m; i++) {
            q.push(q.front()); // ģ�⽫���׵����Ƶ���β
            q.pop();
        }
        cout << q.front() << " "; // ��ʱ�Ķ���Ϊ��M����
        q.pop(); // �����˳���
    }
    return 0;
}
