// 202112304 ±è¿øÈ£

#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a[100];
		int n, m;
		int max = 0;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
			if (a[j] > max) {
				max = a[j];
			}
		}
		int min = 1, mid;
		while (min <= max) {
			mid = (min + max) / 2;
			long long sum = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] > mid) {
					sum += (a[j] - mid);
				}
			}
			if (sum > m) {
				min = mid + 1;
			}
			else if (sum < m) {
				max = mid - 1;
			}
			else {
				printf("%d\n", mid);
				break;
			}
		}
	}
}