#include <cstdio>
#include <list>
using namespace std;

int n, m;
list<int> q; // ������q
list<int>::iterator pos[100001]; // �������������pos
bool erased[100001]; // ��ǵ�ǰλ���Ƿ�ɾ����

int main() {
    q.push_back(1); // ��1��ͬѧ��������q
    pos[1] = q.begin(); // ����Ӧ�ĵ�ַ����pos
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        list<int>::iterator it = pos[k]; // ��k��ͬѧ�ĵ�ַ
        if (p == 1) it++; // ���p==1����Ҫ���뵽�ұߣ���Ҫ��it����һλ
        pos[i] = q.insert(it, i); // ���������ͬʱ��¼�µ�ַ
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int d;
        scanf("%d", &d);
        if (!erased[d]) { // �����ǰλ��û�б�ɾ��
            q.erase(pos[d]); // ɾ������
            erased[d] = true; // ��ǵ�ǰλ���ѱ�ɾ��
        }
    }
    for (list<int>::iterator i = q.begin(); i != q.end(); i++) {
        printf("%d", *i);
        if (i != --q.end()) printf(" ");
        else printf("\n");
    }
    return 0;
}
