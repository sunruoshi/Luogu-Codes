#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001, MOD = 1e9 + 7;

long long n, odd, freq[26], fac[MAXN];
string s;

long long calc(int d) {
    long long res = 1;
    for (int i = d / 2 + 1; i <= d; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    cin >> n >> s;
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        odd += freq[i] % 2;
    }
    if (odd > 1) {
        cout << fac[n];
        return 0;
    }
    long long cnt = 1;
    for (int i = 0; i < 26; i++) {
        cnt = (cnt * calc(freq[i])) % MOD;
    }
    cnt = (cnt * fac[n / 2]) % MOD;
    cout << (fac[n] - cnt + MOD) % MOD;
    return 0;
}
