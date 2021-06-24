#include <cstdio>

int main() {
	int s, v, t;
	scanf("%d %d", &s, &v);
	t = s % v == 0 ? 32 * 60 - s / v - 10 : 32 * 60 - s / v - 11;
	if (t > 24 * 60) {
		t -= 24 * 60;
	}
	printf("%02d:%02d", t / 60, t % 60);
	return 0;
}