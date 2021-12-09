#include <iostream>
#include <string>
using namespace std;

int n, p;
string res = "";

void move(int k) {
    swap(res[k - 1], res[p]);
    swap(res[k], res[p + 1]);
    p = k - 1;
    cout << res << endl;
}

void solve(int f) {
    if (f == 4) {
        move(4);
        move(8);
        move(2);
        move(7);
        move(1);
    } else {
        move(f);
        move((f << 1) - 1);
        solve(f - 1);
    }
}

int main() {
    cin >> n;
    p = n << 1;
    for (int i = 1; i <= n; i++) res += 'o';
    for (int i = n + 1; i <= n << 1; i++) res += '*';
    res += "--";
    cout << res << endl;
    solve(n);
    return 0;
}
