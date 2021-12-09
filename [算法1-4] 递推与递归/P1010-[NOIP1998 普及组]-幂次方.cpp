#include <iostream>
#include <string>
using namespace std;

string solve(int x) {
    string res = "";
    int i = 0;
    if (!x) return "0";
    do {
        if (x & 1) res = (i == 1 ? "2" : "2(" + solve(i) + ")") + (res == "" ? "" : "+") + res;
        i++;
    } while(x >>= 1);
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
