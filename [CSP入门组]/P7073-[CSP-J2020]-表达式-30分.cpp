#include <iostream>
#include <string>
#include <vector>
using namespace std;

int id[1000001];

int main() {
    string s;
    getline(cin, s);
    int n, cnt = 1;
    cin >> n;
    char num[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    string rpn;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x') {
            int j = i + 1, temp = 0;
            while (s[j] != ' ') {
                temp *= 10;
                temp += s[j++] - '0';
            }
            rpn += num[temp];
            id[temp] = cnt++;
        } else if (s[i] == '&' || s[i] == '|' || s[i] == '!') rpn += s[i];
    }
    rpn += '@';
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int idx, p = 0, cnt = 1;
        cin >> idx;
        vector<int> stk;
        while (rpn[p] != '@') {
            if (rpn[p] == '0' || rpn[p] == '1') {
                int num = rpn[p] - '0';
                if (cnt++ == id[idx]) num = !num;
                stk.push_back(num);
            } else if (rpn[p] == '&' || rpn[p] == '|') {
                int num1 = stk.back();
                stk.pop_back();
                int num2 = stk.back();
                stk.pop_back();
                if (rpn[p] == '&') stk.push_back(num1 & num2);
                else stk.push_back(num1 | num2);
            } else {
                stk.back() = !stk.back();
            }
            p++;
        }
        cout << stk[0] << endl;
    }
    return 0;
}
