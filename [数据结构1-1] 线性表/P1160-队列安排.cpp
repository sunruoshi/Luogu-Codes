#include <cstdio>
#include <list>
using namespace std;

int n, m;
list<int> q; // 空链表q
list<int>::iterator pos[100001]; // 链表迭代器数组pos
bool erased[100001]; // 标记当前位置是否被删除了

int main() {
    q.push_back(1); // 将1号同学加入链表q
    pos[1] = q.begin(); // 将对应的地址加入pos
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int k, p;
        scanf("%d%d", &k, &p);
        list<int>::iterator it = pos[k]; // 第k个同学的地址
        if (p == 1) it++; // 如果p==1，需要插入到右边，需要将it右移一位
        pos[i] = q.insert(it, i); // 插入操作，同时记录下地址
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int d;
        scanf("%d", &d);
        if (!erased[d]) { // 如果当前位置没有被删除
            q.erase(pos[d]); // 删除操作
            erased[d] = true; // 标记当前位置已被删除
        }
    }
    for (list<int>::iterator i = q.begin(); i != q.end(); i++) {
        printf("%d", *i);
        if (i != --q.end()) printf(" ");
        else printf("\n");
    }
    return 0;
}
