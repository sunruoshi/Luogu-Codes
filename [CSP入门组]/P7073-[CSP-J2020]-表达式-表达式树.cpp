#include <iostream>
#include <stack>
#include <string>
using namespace std;

const int maxn = 500001;

int index, n, q, value[maxn];
bool check[maxn];
string s;

struct Node {
    int val, op, left, right;
} node[maxn];

int newNode(int val, int op, int left, int right) {
    node[index] = Node({val, op, left, right});
    return index++;
}

void dfs(int root) {
    if (node[root].op > 0) {
        check[node[root].op] = 1;
        return;
    }
    int left = node[root].left, right = node[root].right;
    if (node[root].op == -1) {
        if (node[left].val == 1) dfs(right);
        if (node[right].val == 1) dfs(left);
    } else if (node[root].op == -2) {
        if (node[left].val == 0) dfs(right);
        if (node[right].val == 0) dfs(left);
    } else dfs(left);
}

int main() {
    getline(cin, s);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }
    stack<int> _stack;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') {
            i++;
            int temp = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                temp *= 10;
                temp += s[i] - '0';
                i++;
            }
            _stack.push(newNode(value[temp], temp, -1, -1));
        } else if (s[i] == '&') {
            int right = _stack.top();
            _stack.pop();
            int left = _stack.top();
            _stack.pop();
            int val = node[left].val & node[right].val;
            _stack.push(newNode(val, -1, left, right));
        } else if (s[i] == '|') {
            int right = _stack.top();
            _stack.pop();
            int left = _stack.top();
            _stack.pop();
            int val = node[left].val | node[right].val;
            _stack.push(newNode(val, -2, left, right));
        } else if (s[i] == '!') {
            int left = _stack.top();
            _stack.pop();
            int val = !node[left].val;
            _stack.push(newNode(val, -3, left, -1));
        }
    }
    int root = _stack.top();
    dfs(root);
    scanf("%d", &q);
    while (q--) {
        int idx;
        scanf("%d", &idx);
        printf("%d\n", check[idx] ^ node[root].val);
    }
    return 0;
}

