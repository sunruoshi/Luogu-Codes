#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    vector<int> stu; //����int��vector stu
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        stu.push_back(d); // ��ѧ����ѧ�ż���stu
    }
    for (int i = 0; i < m; i++) {
        int d;
        scanf("%d", &d);
        printf("%d\n", stu[d - 1]);
    }
    return 0;
}
