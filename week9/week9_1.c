// 202112304 김원호

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50001
typedef int TreeNode;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		TreeNode tree[SIZE];
		int n;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			char data[100];
			scanf("%s", data);
			tree[j] = strlen(data);
		}
		for (int j = 1; j <= n; j++) {
			int sum = 4;
			int k = j;
			while (k > 1) {
				sum += tree[k] + 1;
				k = k / 2;
			}
			printf("%d\n", sum);
		}
	}
}
