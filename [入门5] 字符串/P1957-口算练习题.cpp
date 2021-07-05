#include <bits/stdc++.h>
using namespace std;

int main() {
    char op, s[20], temp[4];;
    int n, num1, num2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp[0] >= 'a' && temp[0] <= 'z') {
            op = temp[0];
            cin >> num1 >> num2;
        } else {
            sscanf(temp, "%d", &num1);
            cin >> num2;
        }
        memset(s, 0, sizeof(s));
        if (op == 'a') sprintf(s, "%d+%d=%d", num1, num2, num1 + num2);
        else if (op == 'b') sprintf(s, "%d-%d=%d", num1, num2, num1 - num2);
        else if (op == 'c') sprintf(s, "%d*%d=%d", num1, num2, num1 * num2);
        cout << s << endl << strlen(s) << endl;
    }
    return 0;
}
