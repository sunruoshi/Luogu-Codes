#include <iostream>
#include <string>

using namespace std;

bool isPrime(int d) {
    if (d < 2) return false;
    for (int i = 2; i * i <= d; ++i) {
        if (d % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    int freq[26], max = 0, min = 100;
    for (int i = 0; i < 26; ++i) freq[i] = 0;
    for (int i = 0; i < s.length(); ++i) freq[s[i] - 'a']++;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] == 0) continue;
        max = freq[i] > max ? freq[i] : max;
        min = freq[i] < min ? freq[i] : min;
    }
    if (isPrime(max - min)) cout << "Lucky Word" << endl << max - min;
    else cout << "No Answer" << endl << 0;
    return 0;
}
