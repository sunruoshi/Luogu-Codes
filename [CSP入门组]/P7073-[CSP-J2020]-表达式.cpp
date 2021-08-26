#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int MAXN = 500001;

int idx, n, q, value[MAXN];
bool check[MAXN];
string s;

struct Node {
    int val, opt, left, right;
    Node() {}
    Node(int _v, int _o, int _l, int _r) : val(_v), opt(_o), left(_l), right(_r) {}
} node[MAXN];

int newNode(int val, int opt, int left, int right) {
    node[idx] = Node(val, opt, left, right);
    return idx++;
}

void dfs(int root) {
    if (node[root].opt > 0) {
        check[node[root].opt] = 1;
        return;
    }
    int left = node[root].left, right = node[root].right;
    if (node[root].opt == -1) {
        if (node[left].val == 1) dfs(right);
        if (node[right].val == 1) dfs(left);
    } else if (node[root].opt == -2) {
        if (node[left].val == 0) dfs(right);
        if (node[right].val == 0) dfs(left);
    } else dfs(left);
}

int main() {
    getline(cin, s);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    deque<int> stk;
    for(unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') {
            i++;
            int temp = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                temp *= 10;
                temp += s[i] - '0';
                i++;
            }
            stk.push_back(newNode(value[temp], temp, -1, -1));
        } else if (s[i] == '&') {
            int right = stk.back();
            stk.pop_back();
            int left = stk.back();
            stk.pop_back();
            int val = node[left].val & node[right].val;
            stk.push_back(newNode(val, -1, left, right));
        } else if (s[i] == '|') {
            int right = stk.back();
            stk.pop_back();
            int left = stk.back();
            stk.pop_back();
            int val = node[left].val | node[right].val;
            stk.push_back(newNode(val, -2, left, right));
        } else if (s[i] == '!') {
            int left = stk.back();
            stk.pop_back();
            int val = !node[left].val;
            stk.push_back(newNode(val, -3, left, -1));
        }
    }
    int root = stk.back();
    dfs(root);
    scanf("%d", &q);
    while (q--) {
        int idx;
        scanf("%d", &idx);
        printf("%d\n", check[idx] ^ node[root].val);
    }
    return 0;
}
