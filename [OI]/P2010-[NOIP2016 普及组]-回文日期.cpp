#include <cstdio>

int nextDate(int d) {
    int day = d % 100, month = (d / 100) % 100, year = d / 10000;
    bool leapYear = (!(year % 4) && year % 100) || !(year % 400) ? 1 : 0;
    if (day == 31) {
        if (month == 12) return (year + 1) * 10000 + 101;
        else return year * 10000 + (month + 1) * 100 + 1;
    }
    if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        return year * 10000 + (month + 1) * 100 + 1;
    }
    if (day == 28 && month == 2 && !leapYear) {
        return year * 10000 + (month + 1) * 100 + 1;
    }
    if (day == 29 && month == 2) return year * 10000 + 301;
    return d + 1;
}

int main() {
    int d1, d2;
    scanf("%d %d", &d1, &d2);
    int cnt = 0;
    for (int i = d1; i <= d2; i = nextDate(i)) {
        int x = i, revert = 0;
        while (x > revert) {
            revert = revert * 10 + x % 10;
            x /= 10;
        }
        if (x == revert) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
