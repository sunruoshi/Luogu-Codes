#include <cstdio>

int main() {
	int n, m;
	double maxScore = 0.0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		double max = 0.0, min = 10.0, sum = 0.0, finalScore;
		for (int j = 0; j < m; j++) {
			double score;
			scanf("%lf", &score);
			sum += score;
			max = score > max ? score : max;
			min = score < min ? score : min;
		}
		finalScore = (sum - max - min) / (m - 2);
		maxScore = finalScore > maxScore ? finalScore : maxScore;
	}
	printf("%.2lf", maxScore);
	return 0;
}