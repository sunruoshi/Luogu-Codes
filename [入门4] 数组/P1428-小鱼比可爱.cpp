#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int fish[n], ans[n];
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		scanf("%d", &fish[i]);
		for (int j = 0; j < i; ++j) {
			if (fish[j] < fish[i])
				cnt++;
		}
		ans[i] = cnt;
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}
