#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    unsigned long long n;
    cin >> s >> n;
    while (n > s.size()) {
        unsigned long long p = s.size();
        while (n > p * 2) p *= 2;
        n -= (p + 1);
        if (n == 0) n = p;
    }
    cout << s[n - 1];
    return 0;
}
