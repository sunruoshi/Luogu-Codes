#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int id;
    Node *prev, *next;
    Node(int i = 0) : id(i), prev(NULL), next(NULL) {}
};

int main() {
    int n, m;
    scanf("%d", &n);

    Node* a[n + 1];
    bool erased[n + 1];
    memset(erased, 0, sizeof(erased));

    Node* head = new Node;
    Node* tail = new Node;
    Node* p = new Node(1);
    p->prev = head;
    p->next = tail;
    head->next = p;
    tail->prev = p;
    a[1] = p;

    for (int i = 2; i <= n; i++) {
        int k, opt;
        scanf("%d %d", &k, &opt);
        p = new Node(i);
        Node* pre = opt ? a[k] : a[k]->prev;
        p->next = pre->next;
        pre->next->prev = p;
        pre->next = p;
        p->prev = pre;
        a[i] = p;
    }

    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        if (!erased[x]) {
            Node* pre = a[x]->prev;
            Node* nex = a[x]->next;
            pre->next = nex;
            nex->prev = pre;
            delete(a[x]);
            erased[x] = 1;
        }
    }

    p = head->next;
    while (p != tail) {
        printf("%d", p->id);
        p = p->next;
        if (p == tail) printf("\n");
        else printf(" ");
    }
    return 0;
}
