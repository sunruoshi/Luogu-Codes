#include <cstdio>
#include <iostream>
#include <string>
#include <deque>
#define MAXN 500001
using namespace std;

int n, q, value[MAXN];
bool check[MAXN];
string s;

struct Node {
    int val, opt;
    Node *left, *right;
    Node(int _v, int _o, Node* _l, Node* _r) : val(_v), opt(_o), left(_l), right(_r) {}
};

void dfs(Node* root) {
    if (root->opt > 0) {
        check[root->opt] = 1;
        return;
    }
    Node *left = root->left, *right = root->right;
    if (root->opt == -1) {
        if (left->val == 1) dfs(right);
        if (right->val == 1) dfs(left);
    } else if (root->opt == -2) {
        if (left->val == 0) dfs(right);
        if (right->val == 0) dfs(left);
    } else dfs(left);
}

int main() {
    // freopen("expr.in", "r", stdin);
    // freopen("expr.out", "r", stdout);
    getline(cin, s);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    deque<Node*> stk;
    for(unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') {
            i++;
            int temp = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                temp *= 10;
                temp += s[i] - '0';
                i++;
            }
            stk.push_back(new Node(value[temp], temp, NULL, NULL));
        } else if (s[i] == '&') {
            Node* right = stk.back();
            stk.pop_back();
            Node* left = stk.back();
            stk.pop_back();
            int val = left->val & right->val;
            stk.push_back(new Node(val, -1, left, right));
        } else if (s[i] == '|') {
            Node* right = stk.back();
            stk.pop_back();
            Node* left = stk.back();
            stk.pop_back();
            int val = left->val | right->val;
            stk.push_back(new Node(val, -2, left, right));
        } else if (s[i] == '!') {
            Node* left = stk.back();
            stk.pop_back();
            int val = !left->val;
            stk.push_back(new Node(val, -3, left, NULL));
        }
    }
    Node* root = stk.back();
    dfs(root);
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", check[x] ^ root->val);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
