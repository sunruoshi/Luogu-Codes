#include <cstdio>

struct Node {
    int val;
    Node* next;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node *head = new Node, *cur;
    head->val = 1;
    head->next = NULL;
    cur = head;
    for (int i = 2; i <= n; i++) {
        Node* p = new Node;
        p->val = i;
        p->next = NULL;
        cur->next = p;
        cur = p;
    }
    cur->next = head;
    cur = head;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m - 1; j++) {
            cur = cur->next;
        }
        printf("%d ", cur->next->val);
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return 0;
}
